# Service Auto

Primul proiect la POO.

Pseudo bază de date pentru un mecanic.

---

### Clase

```
Engines─┬─Reciprocating
        └─Rotary

Vehicles─┬─Electric┬─Hybrid
         └─Fossil──┘
           └Egnine*

<exception>──IvalidInput

Menu(Singleton)
└Vector<Vehicles*>
```