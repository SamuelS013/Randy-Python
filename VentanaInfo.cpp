#include "HEADERS/VentanaInfo_Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
using namespace sf;

void ventana_info()
{
	
	RenderWindow window(VideoMode(600, 400), "Información", Style::Titlebar | Style::Close);
	
	Music music;
    if(!music.openFromFile("FX/Fx34.ogg"))
    {
    	system("echo No se pudo cargar un archivo de audio para la ventana Info");
	}
	
	music.setVolume(200);
	music.play();
	
	Texture texture;
	if(!texture.loadFromFile("Imagen/Imagen Info/Marco.png"))
	{
		system("echo No se pudo cargar una imagen de marco&pause");
	}
	
	Sprite sprite(texture);
	sprite.setPosition(30, 30);
	sprite.setScale(1.86f, 1.40f);
	
    RectangleShape borde_superior(Vector2f(600, 220));
    borde_superior.setFillColor(Color::Black);


	Font font1, font2, font3, font4;
	if (!font1.loadFromFile("Fuentes/MEGRATH.otf")){
		system("echo No se pudo caragr la fuente&pause");
	}
	
	if(!font2.loadFromFile("Fuentes/Cyberpunk.otf"))
	{
		system("echo No se pudo cargar la fuente 2 en la ventana info&pause");
	}
	
	if(!font3.loadFromFile("Fuentes/MONSTER OF FANTASY.otf"))
	{
		system("echo No se pudo cargar la fuente 2 en la ventana info&pause");
	}
	
	if (!font4.loadFromFile("Fuentes/SophiaFrancesca.ttf")){
		system("echo No se pudo caragr la fuente&pause");
	}
	
	//Creación del texto para los botones
    Text texto_titulo("INFORMACIÓN ACERCA DE ESTE JUEGO", font1, 20);
    texto_titulo.setFillColor(Color::White);
    texto_titulo.setPosition(74, 75);
    texto_titulo.setOutlineColor(Color::Black);
    texto_titulo.setOutlineThickness(3);
    Text texto_creadores("BY: RETRO REVOLUTION STUDIOS", font2, 15);
    texto_creadores.setFillColor(Color::White);
    texto_creadores.setPosition(160, 162);
    texto_creadores.setOutlineColor(Color::Black);
    texto_creadores.setOutlineThickness(2);
    
    Text texto_tutorial("¿CÓMO JUGAR?", font4, 30);
    texto_tutorial.setFillColor(Color(14, 216, 112));
    texto_tutorial.setPosition(40, 225);
    Text texto_tutorial2("Si necesita una guía para jugar a nuestro juego pulse aquí", font1, 13);
    texto_tutorial2.setFillColor(Color::White);
    texto_tutorial2.setPosition(40, 265);
    Text texto_tutorial3("REPORTAR UN RPOBLEMA", font4, 30);
    texto_tutorial3.setFillColor(Color(14, 216, 112));
    texto_tutorial3.setPosition(40, 300);
    Text texto_tutorial4("Déjanos un comentario a la siguente direccion gmail: \njaviermurillo@gmail.com", font1, 13);
    texto_tutorial4.setFillColor(Color::White);
	texto_tutorial4.setPosition(40, 340);
	
    
	while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
                
		}
		
        window.clear(Color::Black);
    
        window.draw(texto_tutorial);
        window.draw(texto_tutorial2);
        window.draw(texto_tutorial3);
        window.draw(texto_tutorial4);
        window.draw(borde_superior);
        window.draw(sprite);
        window.draw(texto_creadores);
        window.draw(texto_titulo);

        window.display();
    }
    
}
