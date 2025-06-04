#pragma once
#include "Afichmation.h"
#include <SFML/Graphics.hpp>
#include "Texto.h"
#include "Objeto.h"
using namespace sf;

class Bloque : public Objeto {
private:
    Texto numero;  // muestra el n�mero del bloque.

    // Variables para la animaci�n de rebote
    bool esElCorrecto = false;     // detecta que el n�mero es el correcto.
    bool fueElCorrecto = false;    // detecta que ya fueCorrecto y no restar tiempo.
    float tiempoAnim = 0.f;        // Tiempo acumulado desde que empez� la animaci�n.
    float duracionAnim = 0.4f;     // Duraci�n total de la animaci�n.
    float alturaRebote = -10.f;    // Altura del rebote .
    Vector2f posicionOriginal;     // Posici�n inicial del bloque.

public:

    Bloque(Vector2f pos, int num);

    // Dibuja el bloque y su n�mero en la ventana.
    void dibujar(RenderWindow& w) override;


    // Animaci�n de rebote si el bloque es el correcto.
    void animacion(float deltaTime) override;

    // Marca al bloque como correcto.
    void esCorrecto();

    // Devuelve true si el bloque ya fue marcado y evitar restar tiempo.
    bool fueCorrecto();

    // Devuelve el n�mero que contiene el bloque.
    int verNumero();

    // Cambia la posici�n del bloque en pantalla.
    void quePos(Vector2f pos);
};


