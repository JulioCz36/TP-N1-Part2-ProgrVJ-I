#pragma once
#include "Afichmation.h"
#include <SFML/Graphics.hpp>
#include "Audio.h"
#include "Objeto.h"
using namespace sf;

class Personaje : public Objeto {
    // Sonidow de salto,aterrizaje,l correr,al caminar
    Audio jump,land, running, walk;

    float velocidad = 90.f;          // Velocidad de movimiento horizontal
    float velocidadSalto = 330.f;    // Velocidad inicial al saltar
    float gravedad;                  // Valor de gravedad del mundo (inyectado)
    float velocidadY = 0.f;          // Velocidad vertical


    bool enElAire = false;       // Si el personaje est�  en el aire
    bool saltoIniciado = false; // Detectar comienzo del salto
    bool caidaIniciada = false; // Detectar comienzo de una ca�da

    Keyboard::Key izq = Keyboard::A;         // Tecla para ir a la izquierda
    Keyboard::Key der = Keyboard::D;         // Tecla para ir a la derecha
    Keyboard::Key correr = Keyboard::LShift; // Tecla para correr
    Keyboard::Key saltar1 = Keyboard::Space; // Tecla principal para saltar
    Keyboard::Key saltar2 = Keyboard::W;     // Tecla alternativa para saltar

public:
    Personaje(Vector2f pos, float gravedadMundo);

    void actualizar(float deltaTime) override;          // L�gica de movimiento y f�sica
    void manejarEventos(Event& e);             // Procesamiento de eventos del jugador


    void animacion(float deltaTime) override;  // Cambia la animaci�n seg�n movimiento
    void mover(float deltaTime);               // Aplica movimiento horizontal
    void aplicarGravedad(float deltaTime);     // Aplica la gravedad al jugador

 
    bool estaQuieto();                         // Indica si el personaje est� quieto
    void verificarLimitesPantalla();           // Evita que salga de la pantalla
    FloatRect verBounds() override;            // Devuelve los l�mites del sprite

    float verVelocidadY() const { return velocidadY; } // Getter de velocidad vertical
    void queVelocidadY(float v) { velocidadY = v; }    // Setter de velocidad vertical

};


