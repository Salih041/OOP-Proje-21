# OOP-Proje-21

1.  **`main` branch'ine push yasak**
2.  Her class için **yeni bir branch** aç (`isim/class-ismi`).
3.  Kodları göndermeden önce mutlaka `main` branch'inden güncellemeleri çek (`git pull`).
4.  İş bittiğinde GitHub üzerinden **Pull Request (PR)** aç.

## Kurulum

```bash
# 1. Projeyi bilgisayarına klonla
git clone https://github.com/Salih041/OOP-Proje-21

# 2. Proje klasörüne gir
cd OOP-Proje-21

# 3. Hangi branch'te olduğuna bak (main yazmalı)
git branch
```

## Çalışma Akışı

```bash
# 1. Günceli çek
git checkout main
git pull origin main

# 2. Branch aç (Yalnızca ilk seferde)
git checkout -b isim/gorev-adi

# 2.1 Kaldığın yerden devam ederken
git checkout <branch-adi>

# 3. Değişiklikleri gönder 
git add .
git commit -m "mesaj"
git push origin isim/gorev-adi

# 4. Merge isteği
# Github -> Compare & Pull Request
