#include "HEADERS/VentanaAjustes_Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>

using namespace sf;

void ventana_ajustes(){
	
	RenderWindow window(VideoMode(600, 400), "Ajustes", Style::Titlebar | Style::Close);
	
	//RectangleShape error(Vector2f(600, 100));
	//error.setFillColor(Color::Black);
	//error.setPosition(0, 150);
	
	Music music;
	
	if(!music.openFromFile("FX/Fx34.ogg"))
	{
		system("echo No se pudo cargar un archivo de audio para la ventana Ajustes&pause");
	}
	
	music.setVolume(200);
	music.play();
	
	Font font;
	if (!font.loadFromFile("Fuentes/Cyberpunk.otf")){
		system("echo No se pudo cargar la fuente&pause");
	}
	
    Text texto_ajustes("AJUSTES", font, 40);
    texto_ajustes.setFillColor(Color::White);
    texto_ajustes.setPosition(30, 5.5);
    
    Texture musica, efectosSonido;
    
	//Text textError("Esta parte del juego se encuentra en \nmateniemiento y sera resuelto en breve...", font, 20);
	//textError.setFillColor(Color::White);
	//textError.setPosition(50, 170);
	
    if (!musica.loadFromFile("Imagen/Imagen Ajustes/Musica.png")){
		system("echo No se pudo caragr la imagenn de musica&pause");
	}
	
	if (!efectosSonido.loadFromFile("Imagen/Imagen Ajustes/EfectosSonido.png")){
		system("echo No se pudo caragr la imagenn de efectos de sonido&pause");
	}
    
    Sprite sprite_musica(musica), sprite_efectosSonido(efectosSonido);
    
    sprite_musica.setScale(0.4, 0.35);
    sprite_efectosSonido.setScale(0.4, 0.35);
    sprite_musica.setPosition(50, 90);
    sprite_efectosSonido.setPosition(50, 170);
    
    RectangleShape borde_superior(Vector2f(600, 60));
    borde_superior.setFillColor(Color(7, 17, 60));
    borde_superior.setOutlineColor(Color(99, 203, 255));
    borde_superior.setOutlineThickness(2);
    
    RectangleShape borde_decorativo(Vector2f(530, 400));
	borde_decorativo.setFillColor(Color(201, 94, 255, 10));
	borde_decorativo.setOutlineColor(Color(99, 203, 255));
	borde_decorativo.setOutlineThickness(3);
	borde_decorativo.setPosition(35, -30);
	
	RectangleShape boton_musica(Vector2f(92, 40));
	boton_musica.setFillColor(Color::Black);
	boton_musica.setOutlineColor(Color(83, 169, 212));
	boton_musica.setOutlineThickness(3);
	boton_musica.setPosition(320, 120);
	
	RectangleShape boton_musica_encendido(Vector2f(35, 34));
	boton_musica_encendido.setFillColor(Color(83, 169, 212));
	boton_musica_encendido.setPosition(373, 123);
    
    RectangleShape boton_fx(Vector2f(92, 40));
	boton_fx.setFillColor(Color::Black);
	boton_fx.setOutlineColor(Color(83, 169, 212));
	boton_fx.setOutlineThickness(3);
	boton_fx.setPosition(320, 200);
	
	RectangleShape boton_fx_encendido(Vector2f(35, 34));
	boton_fx_encendido.setFillColor(Color(83, 169, 212));
	boton_fx_encendido.setPosition(373, 203);
    
	while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)			
                window.close();
                
                
                if (event.type == Event::MouseButtonPressed)
				{
					if(event.mouseButton.button == Mouse::Left)
					{
					
						Vector2i mousePos = Mouse::getPosition(window);
						Vector2f woldPos = window.mapPixelToCoords(mousePos);
					
						if (boton_musica.getGlobalBounds().contains(woldPos))
						{
							boton_musica_encendido.setPosition(323, 123);
							boton_musica_encendido.setFillColor(Color(83, 169, 212, 172));
						}
					}
				}
				
				if (event.type == Event::MouseButtonPressed)
				{
					if(event.mouseButton.button == Mouse::Left)
					{
					
						Vector2i mousePos = Mouse::getPosition(window);
						Vector2f woldPos = window.mapPixelToCoords(mousePos);
					
						if (boton_fx.getGlobalBounds().contains(woldPos))
						{
							boton_fx_encendido.setPosition(323, 203);
							boton_fx_encendido.setFillColor(Color(83, 169, 212, 172));
						}
					}
				}
		}
	
		
        window.clear(Color(2, 8, 25));
        window.draw(borde_decorativo);
        window.draw(borde_superior);
        window.draw(texto_ajustes);
        window.draw(sprite_musica);
        window.draw(boton_musica);
        window.draw(boton_musica_encendido);
        window.draw(sprite_efectosSonido);
        window.draw(boton_fx);
        window.draw(boton_fx_encendido);
        //window.draw(error);
        //window.draw(textError);

        window.display();
    }
}
