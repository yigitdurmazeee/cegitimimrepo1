"""
CNN (Convolutional Neural Network) - Detaylı Algoritma ve Uygulama
==================================================================

CNN ALGORITMASI - Adımlar:
1. VERİ HAZIRLAMA: Eğitim ve test verilerini yükleme, normalize etme
2. MODEL MİMARİSİ: Conv, ReLU, Pooling katmanlarını tanımlama
3. FORWARD PASS: Verinin ağdan ileri geçişi
4. LOSS HESAPLA: Çıktı ile gerçek değer arasındaki farkı hesaplama
5. BACKWARD PASS: Gradyentleri hesaplama (backpropagation)
6. OPTIMIZER: Ağırlıkları güncellemek (SGD, Adam vb.)
7. TEKRAR: Öğrenene kadar 3-6 adımlarını tekrarlama

PyTorch ile Uygulanmış CNN:
"""

import torch
import torch.nn as nn
import torch.optim as optim
import torchvision.transforms as transforms
from torchvision.datasets import MNIST
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt

# ============================================================================
# ADIM 1: VERİ HAZIRLAMA (Data Preparation)
# ============================================================================
print("ADIM 1: VERİ HAZIRLAMA")
print("-" * 50)

# Veriyi normalize etmek için transform tanımla
# Normalizasyon: (resim - ortalama) / standart_sapma
transform = transforms.Compose([
    transforms.ToTensor(),  # Numpy array'ini torch tensor'ına dönüştür
    transforms.Normalize((0.1307,), (0.3081,))  # MNIST ortalaması ve std
])

# MNIST veri setini indir ve yükle
print("MNIST veri seti yükleniyor...")
train_dataset = MNIST(root='./data', train=True, download=True, transform=transform)
test_dataset = MNIST(root='./data', train=False, download=True, transform=transform)

# DataLoader: Verileri mini-batch'ler halinde sağlar
batch_size = 64
train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)

print(f"Eğitim verisi: {len(train_dataset)} resim")
print(f"Test verisi: {len(test_dataset)} resim")
print(f"Batch boyutu: {batch_size}")
print(f"Her resim boyutu: 1x28x28 (kanal x genişlik x yükseklik)")
print()

# ============================================================================
# ADIM 2: MODEL MİMARİSİ (CNN Architecture)
# ============================================================================
print("ADIM 2: MODEL MİMARİSİ")
print("-" * 50)

class SimpleCNN(nn.Module):
    """
    Basit bir CNN modeli:

    KATMANLAR:
    - Conv2d: Konvolüsyon işlemi (feature extraction - özellik çıkarma)
    - ReLU: Aktivasyon fonksiyonu (non-linearity - doğrusallık kırma)
    - MaxPool2d: Pooling (boyut küçültme, en önemli özelliği tutma)
    - Flatten: Tensor'ı 1D vektöre çevirme
    - Linear (FC): Tam bağlı katmanlar (sınıflandırma)
    """

    def __init__(self):
        super(SimpleCNN, self).__init__()

        # KATMAN 1: Konvolüsyon
        # in_channels=1 (gri tonlu resim), out_channels=32 (öğrenilecek filter sayısı)
        # kernel_size=3 (3x3 filtre), padding=1 (boyut koruması)
        self.conv1 = nn.Conv2d(in_channels=1, out_channels=32, kernel_size=3, padding=1)
        # Çıktı: 32x28x28

        # AKTIVASYON: ReLU = max(0, x)
        self.relu1 = nn.ReLU()

        # POOLING: 2x2 max pooling (boyutu yarıya indir)
        self.pool1 = nn.MaxPool2d(kernel_size=2, stride=2)
        # Çıktı: 32x14x14

        # KATMAN 2: İkinci Konvolüsyon
        self.conv2 = nn.Conv2d(in_channels=32, out_channels=64, kernel_size=3, padding=1)
        # Çıktı: 64x14x14

        self.relu2 = nn.ReLU()
        self.pool2 = nn.MaxPool2d(kernel_size=2, stride=2)
        # Çıktı: 64x7x7

        # FLATTEN: 64 * 7 * 7 = 3136 boyutlu vektör
        # Bu vektörü sınıflandırmak için fully connected katmana göndeririz

        # FULLY CONNECTED (Tam Bağlı) KATMANLAR:
        # Sınıflandırma için (MNIST = 10 sınıf: 0-9)
        self.fc1 = nn.Linear(64 * 7 * 7, 128)  # 3136 -> 128 (feature reduction)
        self.relu3 = nn.ReLU()

        self.fc2 = nn.Linear(128, 10)  # 128 -> 10 (sınıf sayısı)
        # Çıktı: 10 (MNIST sınıfları: 0,1,2,...,9)

    def forward(self, x):
        """
        FORWARD PASS (İleri Geçiş):
        Verinin ağdan geçişini adım adım gösterir.
        """
        # x boyutu: [batch_size, 1, 28, 28]

        # BLOK 1: Conv + ReLU + Pool
        x = self.conv1(x)        # Konvolüsyon işlemi
        x = self.relu1(x)        # Aktivasyon
        x = self.pool1(x)        # Pooling

        # BLOK 2: Conv + ReLU + Pool
        x = self.conv2(x)        # İkinci konvolüsyon
        x = self.relu2(x)        # Aktivasyon
        x = self.pool2(x)        # Pooling

        # FLATTEN: Tensor'ı 1D vektöre dönüştür
        x = x.view(x.size(0), -1)  # [batch_size, 3136]

        # FULLY CONNECTED
        x = self.fc1(x)          # Gizli katman
        x = self.relu3(x)        # Aktivasyon
        x = self.fc2(x)          # Çıktı katmanı

        return x

# Model oluştur
model = SimpleCNN()
print("Model mimarisi:")
print(model)
print()

# ============================================================================
# ADIM 3, 4, 5, 6: HİPERPARAMETRELER VE OPTİMİZER
# ============================================================================
print("ADIM 3-6: HİPERPARAMETRELER VE OPTİMİZER AYARI")
print("-" * 50)

# LOSS FUNCTION (Kayıp Fonksiyonu):
# CrossEntropyLoss = Softmax + NLL Loss
# Sınıflandırma problemleri için en yaygın kullanılan loss
criterion = nn.CrossEntropyLoss()

# OPTIMIZER (Optimizasyon Algoritması):
# Adam: Adaptive Learning Rate (uyarlanabilir öğrenme hızı)
learning_rate = 0.001
optimizer = optim.Adam(model.parameters(), lr=learning_rate)

print(f"Loss Fonksiyonu: CrossEntropyLoss")
print(f"Optimizer: Adam (lr={learning_rate})")
print()

# ============================================================================
# ADIM 7: EĞİTİM DÖNGÜSÜ (Training Loop)
# ============================================================================
print("ADIM 7: BAŞLANGICIN ÖĞRETİM SÜRECİ")
print("-" * 50)

num_epochs = 5
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = model.to(device)

train_losses = []
test_losses = []

for epoch in range(num_epochs):
    print(f"\nEpoch {epoch+1}/{num_epochs}")

    # --- EĞİTİM FAZLARI ---
    model.train()  # Modeli eğitim moduna koy (dropout, batch norm aktif)
    epoch_loss = 0

    for batch_idx, (images, labels) in enumerate(train_loader):
        # Veriyi GPU/CPU'ya taşı
        images = images.to(device)
        labels = labels.to(device)

        # ADIM 3: FORWARD PASS
        # Verileri modelden geçir, çıktı al
        outputs = model(images)  # [batch_size, 10]

        # ADIM 4: LOSS HESAPLA
        # Ağın çıktısı ile gerçek etiket arasındaki farkı hesapla
        loss = criterion(outputs, labels)

        # ADIM 5: BACKWARD PASS (Backpropagation)
        # Optimizer'ı sıfırla (eski gradyentleri temizle)
        optimizer.zero_grad()

        # Kayıp fonksiyonunun türevini al (gradyent hesapla)
        # Zincir kuralı (chain rule) ile tüm ağdaki gradyentler hesaplanır
        loss.backward()

        # ADIM 6: AĞIRLIKLARI GÜNCELLE
        # optimizer.step(): Gradyentleri kullanarak ağırlıkları güncelle
        # w_new = w_old - learning_rate * gradient
        optimizer.step()

        epoch_loss += loss.item()

        if (batch_idx + 1) % 100 == 0:
            print(f"  Batch {batch_idx+1}/{len(train_loader)}, Loss: {loss.item():.4f}")

    avg_loss = epoch_loss / len(train_loader)
    train_losses.append(avg_loss)
    print(f"Epoch Ortalama Loss: {avg_loss:.4f}")

    # --- TEST FAZLARI ---
    model.eval()  # Modeli değerlendirme moduna koy
    test_loss = 0
    correct = 0
    total = 0

    with torch.no_grad():  # Gradyent hesapla verme (bellek tasarrufu)
        for images, labels in test_loader:
            images = images.to(device)
            labels = labels.to(device)

            outputs = model(images)
            loss = criterion(outputs, labels)
            test_loss += loss.item()

            # Doğru tahminleri say
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()

    avg_test_loss = test_loss / len(test_loader)
    accuracy = 100 * correct / total
    test_losses.append(avg_test_loss)

    print(f"Test Loss: {avg_test_loss:.4f}, Accuracy: {accuracy:.2f}%")

print("\n" + "="*50)
print("EĞİTİM TAMAMLANDI!")
print("="*50)

# ============================================================================
# SONUÇ VE GÖRSELLEŞTIRME
# ============================================================================
print("\nEĞİTİM SONUÇLARI:")
print(f"Final Eğitim Loss: {train_losses[-1]:.4f}")
print(f"Final Test Loss: {test_losses[-1]:.4f}")
print(f"Final Test Doğruluğu: {accuracy:.2f}%")

# Grafik çiz
plt.figure(figsize=(10, 5))
plt.plot(train_losses, label='Eğitim Loss', marker='o')
plt.plot(test_losses, label='Test Loss', marker='s')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.title('CNN Eğitim Süreci - Loss Değişimi')
plt.legend()
plt.grid(True)
plt.savefig('cnn_training.png')
print("\nGrafik kaydedildi: cnn_training.png")

# ============================================================================
# CNN ALGOITMASI ÖZET
# ============================================================================
print("\n" + "="*70)
print("CNN ALGORİTMASI - TEKRAR TEKRARı (Epoch içinde 1 batch için):")
print("="*70)
print("""
┌─────────────────────────────────────────────────────────┐
│ 1. FORWARD PASS: x → Conv1 → ReLU → Pool → Conv2 → ... │
│                 → ReLU → Pool → FC1 → FC2 → output      │
├─────────────────────────────────────────────────────────┤
│ 2. LOSS HESAPLA: loss = CrossEntropyLoss(output, label) │
├─────────────────────────────────────────────────────────┤
│ 3. BACKWARD PASS: ∂loss/∂w hesapla (chain rule ile)     │
├─────────────────────────────────────────────────────────┤
│ 4. OPTIMIZER: w = w - lr * ∂loss/∂w                      │
├─────────────────────────────────────────────────────────┤
│ 5. TEKRAR: Sonraki batch için 1-4 arası adımları tekrar │
│            tüm batch'ler tamamlanana kadar              │
└─────────────────────────────────────────────────────────┘

TEMEL KAVRAMLAR:
• Konvolüsyon: Özellik çıkarma (edge, texture vb.)
• ReLU: f(x) = max(0, x) - Non-linear aktivasyon
• Pooling: Boyut küçültme, önemli bilgiyi tutma
• Backpropagation: Zincir kuralı ile gradyent hesabı
• Optimizer: Gradyent descent ile ağırlık güncelleme
• Epoch: Tüm eğitim verisinden 1 geçiş
""")
