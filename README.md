# CPP02

Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form

---

## ex00: Orthodox Canonical Class Form (OCF) Nedir?

Doğru ve güvenli nesne kopyalama ve imha sağlayan **4 özel üye işlevinden** oluşan standart settir.

| # | Fonksiyon | İmza |
|---|-----------|------|
| 1 | Default constructor | `MyClass();` |
| 2 | Copy constructor | `MyClass(const MyClass& other);` |
| 3 | Copy assignment operator | `MyClass& operator=(const MyClass& other);` |
| 4 | Destructor | `~MyClass();` |

---

### 1. Default Constructor

- Nesne oluşturulduğunda çağrılır.
- Üye değişkenleri başlangıç değerine ayarlar.

---

### 2. Copy Constructor

- Var olan bir nesneden **yeni** nesne oluşturulduğunda çağrılır:
  ```cpp
  Fixed b(a);   // veya
  Fixed b = a;  // (bu da copy constructor'dır!)
  ```
- `const Fixed& other` — orijinali değiştirme, referansla al (kopyalama yok).

---

### 3. Copy Assignment Operator

- Var olan bir nesneye **başka** var olan nesne atandığında çağrılır:
  ```cpp
  Fixed c;
  c = b;   // işte burada çağrılır
  ```
- `return *this` → zincirleme atama için: `a = b = c;`
- **Kendine atama kontrolü** şart! (`if (this != &other)`)

#### Copy Assignment Operator Ne İçin Kullanılır?
- İki ayrı, zaten var olan nesne arasında değer aktarmak için.

##### Copy Constructor ile Farkı
- Ne zaman çağrılır?
  - Copy Constructor: Yeni bir nesne oluşturulurken, başka nesneden kopyalanarak
  - Copy Assignment Operator: İki nesne de zaten var, birinin değeri diğerine atanıyor

---

### 4. Destructor

- Nesne scope'dan çıktığında otomatik çağrılır.
- Dinamik bellek varsa (`new` ile ayrılan) burada `delete` edilir.

---

### Çağrılma Sırası (main.cpp örneği)

```
Fixed a;       → Default constructor
Fixed b(a);    → Copy constructor
Fixed c;       → Default constructor
c = b;         → Copy assignment operator
// scope bitiyor...
~Fixed()       → 3 kez (c, b, a için ters sırayla)
```

> **Rule of Three:** Copy constructor, copy assignment operator veya destructor'dan **birini** kendin yazıyorsan, büyük ihtimalle **üçünü de** yazman gerekir.
> C++11'de buna **Rule of Five** (move semantics eklenince) denir.
