# Triângulo de Sierpinski

Este projeto implementa o **Triângulo de Sierpinski**, uma estrutura fractal, utilizando a linguagem **C** e a biblioteca **SDL2**.  
Ele foi desenvolvido para a disciplina de **Vida Artificial na Computação**, como parte dos estudos sobre fractais, auto-similaridade e sistemas complexos.

---


## 🚀 Tecnologias Utilizadas
- **C (GCC ou compatível)**
- **SDL2**

---

## 🖥️ Como Compilar e Executar

### 🔧 Instalação das Dependências

- **Ubuntu/Debian**
  ```bash
  sudo apt update
  sudo apt install build-essential libsdl2-dev
  ```

- **Fedora**
  ```bash
  sudo dnf install gcc SDL2-devel
  ```

- **Arch Linux**
  ```bash
  sudo pacman -S sdl2
  ```

- **Windows**
  - Instale o [MSYS2](https://www.msys2.org/) e configure o GCC.
  - Instale o pacote `mingw-w64-x86_64-SDL2`.

---

### ▶️ Compilando o Projeto

1. Clone o repositório:
   ```bash
   git clone https://github.com/AnabelCristina/TrianguloDeSierpinski.git
   cd TrianguloDeSierpinski
   ```

2. Compile o código com:
   ```bash
   gcc main.c -o sierpinski -lSDL2 -lm
   ```

3. Execute o programa:
   ```bash
   ./sierpinski
   ```

---

## 📸 Exemplo de Saída

Alterando a linha "level = 3", é possivel gerar diferentes fractais.

Level = 3
![alt text](image.png)

Level = 5
![alt text](image-2.png)

Level = 6
![alt text](image-1.png)
---

## 🎓 Créditos

Projeto desenvolvido por **Anabel Cristina** durante a disciplina *Vida Artificial na Computação*.  
Faculdade: (adicione o nome da sua instituição aqui, se quiser)
