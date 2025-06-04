#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Texto.h"
#include "Audio.h"

using namespace sf;
using namespace std;

// Clase HUD: Maneja la interfaz gr�fica 
class HUD{
	//Controles de guias
	Texture teclas_texture;
	Sprite controles;

	// texto muestra tiempo o estado, reinicio indica c�mo reiniciar el juego
	Texto texto, reinicio;

	// Sonidos tic-tac,reinicio parpadeando,victoria, derrota
	Audio reloj,restart, win, over;

	// Tiempo restante de la partida
	float tiempoRestante = 61.f; 
	// Indica si se acab� el tiempo
	bool terminado = false;
	// Indica si el jugador gan�
	bool gano = false;

	// controlar el parpadeo
	float tiempoParpadeo = 0.f;
	// alternar visibilidad
	bool mostrarReinicio = false;
	// Guarda el valor anterior de mostrarReinicio
	bool mostrarReinicioAnterior = true;

	// tiempo desde que termin� la partida
	float tiempoDesdeFin = 0.f;
	// Controla que los sonidos de fin
	bool sonidoCondicion = false;

public:
	HUD();
	// Actualiza el HUD cada frame
	void actualizar(float deltaTime);
	// Dibuja los textos del HUD en la ventana
	void dibujar(RenderWindow& w);
	// Cambia el contenido del texto
	void actualizarTexto();

	// Penaliza al jugador 
	void esIncorrecto();
	// Marca que gan� la partida
	void elGano();
	// Devuelve si el tiempo se termin�
	bool seTermino();
};

