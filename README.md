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

```cpp
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}
```

- Nesne oluşturulduğunda çağrılır: `Fixed a;`
- Üye değişkenleri başlangıç değerine ayarlar.

---

### 2. Copy Constructor

```cpp
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // assignment operator'ı kullanır
}
```

- Var olan bir nesneden **yeni** nesne oluşturulduğunda çağrılır:
  ```cpp
  Fixed b(a);   // veya
  Fixed b = a;  // (bu da copy constructor'dır!)
  ```
- `const Fixed& other` — orijinali değiştirme, referansla al (kopyalama yok).

---

### 3. Copy Assignment Operator

```cpp
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)          // kendine atama kontrolü!
        this->_rawBits = other.getRawBits();
    return *this;
}
```

- Var olan bir nesneye **başka** var olan nesne atandığında çağrılır:
  ```cpp
  Fixed c;
  c = b;   // işte burada çağrılır
  ```
- `return *this` → zincirleme atama için: `a = b = c;`
- **Kendine atama kontrolü** şart! (`if (this != &other)`)

---

### 4. Destructor

```cpp
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
```

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
