#include "HEADERS/NuevoUsuario/CrearNuevoUsuario_Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

int crearNuevoUsuario()
{
	
	RenderWindow window(VideoMode(300, 100), "Perfil de Usuario", Style::Titlebar | Style::Close);
    //boton_jugar.setPosition(160, 150); // Parte inferior derechq

	Font font, font2;
	if (!font.loadFromFile("Fuentes/MEGRATH.otf")){
		system("echo No se pudo caragr la fuente&pause");
	}
	
	if (!font2.loadFromFile("Fuentes/SophiaFrancesca.ttf")){
		system("echo No se pudo caragr la fuente&pause");
	}
	//Creación del texto para los botones
    Text crearnuevo("Nuevo", font, 25);
    crearnuevo.setFillColor(Color::White);
    crearnuevo.setPosition(465, 350);
    
    Text titulo("Ingresa un nuevo nombre", font2, 25);
    titulo.setFillColor(Color::White);
    titulo.setPosition(10, 15);
    titulo.setOutlineColor(Color::Black);
    titulo.setOutlineThickness(1);
    
    Text texto_usuario("", font, 15);
    texto_usuario.setPosition(50, 60);
    texto_usuario.setOutlineColor(Color::Black);
    texto_usuario.setOutlineThickness(1);
    
    RectangleShape borde(Vector2f(230, 20));
    borde.setFillColor(Color(0, 0, 0, 100));
    borde.setPosition(40, 60);
    
    
    string userInput;
    
    
   /* if (event.type == Event::MouseButtonPressed){
				if(event.mouseButton.button == Mouse::Left){
					Vector2i mousePos = Mouse::getPosition(window);
					
					//Vector2f woldPos = window.mapPixelToCoords(mousePos);
					
					if (crearnuevo.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))){
						ventana_perfil();
					}
				}
		}*/
    
	while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)
                window.close();
                
            if (event.type == Event::TextEntered)
            {
            	
            	
            	if (event.text.unicode == '\b')
            	{
            		if (!userInput.empty())
            		{
            			userInput.erase(userInput.size() - 1);
					}
					else if (event.text.unicode == '\r')
					{
						ofstream file("output.txt");
						
						if (file.is_open())
						{
								file << userInput;
								file.close();
								
								userInput.clear();
						}
						else if(userInput.size() < 20)
						{
								userInput += static_cast<char> (event.text.unicode);
						}
					}
					
					texto_usuario.setString(userInput);
				}
				
			}
		}
		
		texto_usuario.setString(userInput);
        window.clear(Color(0, 133, 199));
        window.draw(titulo);
        window.draw(crearnuevo);
        window.draw(borde);
        window.draw(texto_usuario);

        window.display();
    }
}
