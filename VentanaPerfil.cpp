#include "HEADERS/VentanaPerfil_Header.h"
#include "HEADERS/NuevoUsuario/CrearNuevoUsuario_Header.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/window.hpp>
#include <cstdlib>
using namespace sf;

void ventana_perfil()
{
	
	RenderWindow window(VideoMode(600, 400), "Perfil de Usuario", Style::Titlebar | Style::Close);
	
	Music music;
    
    if(!music.openFromFile("FX/Fx34.ogg"))
    {
    	system("echo No se pudo cargar un archivo de audio para la ventana Perfil");
	}
	
	music.setVolume(200);
	music.play();
	
	// Crear botones
    RectangleShape borde_superior(Vector2f(600, 60));
    borde_superior.setFillColor(Color(23, 0, 104));
    borde_superior.setOutlineColor(Color(0, 0, 0));
    borde_superior.setOutlineThickness(3);
	
	RectangleShape lineaInfo_horizontal(Vector2f(600, 50));
	lineaInfo_horizontal.setFillColor(Color(23, 0, 180));
	lineaInfo_horizontal.setPosition(0, 63);
	
	RectangleShape lineaOpc_horizontal(Vector2f(600, 80));
	lineaOpc_horizontal.setFillColor(Color(180, 7, 226, 80));
	lineaOpc_horizontal.setPosition(0, 340);
	lineaOpc_horizontal.setOutlineColor(Color(23, 0, 180));
	lineaOpc_horizontal.setOutlineThickness(2);
	
	RectangleShape recuadroUsuario(Vector2f(500, 50));
	recuadroUsuario.setFillColor(Color(40, 7, 95, 120));
	recuadroUsuario.setPosition(52, 127);

	Font font;
	if (!font.loadFromFile("Fuentes/MEGRATH.otf")){
		system("echo No se pudo caragr la fuente&pause");
	}
	//Creación del texto para los botones
    Text texto_perfil("Perfil", font, 30);
    texto_perfil.setFillColor(Color::White);
    texto_perfil.setPosition(30, 10);
    
    
    Text nombre("Nombre de Usuario", font, 15);
    nombre.setFillColor(Color::White);
    nombre.setPosition(90, 75);
    nombre.setOutlineColor(Color::Black);
    nombre.setOutlineThickness(1);
    
    Text ultimaModificacion("Ultima Modificación", font, 15);
    ultimaModificacion.setFillColor(Color::White);
    ultimaModificacion.setPosition(330, 75);
    ultimaModificacion.setOutlineColor(Color::Black);
    ultimaModificacion.setOutlineThickness(1);
    
    
    Text crearnuevo("Nuevo", font, 25);
    crearnuevo.setFillColor(Color::White);
    crearnuevo.setPosition(465, 350);
    
    Text seleccionar("Seleccionar", font, 25);
    seleccionar.setFillColor(Color::White);
	seleccionar.setPosition(30, 350);
    
    Text borrar("Borrar", font, 25);
    borrar.setFillColor(Color::White);
    borrar.setPosition(220, 350);    
    
	while (window.isOpen())
    {
 
        Event event;
        while (window.pollEvent(event))
        {
  
            if (event.type == Event::Closed)
                window.close();
                
                
        	if (event.type == Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == Mouse::Left)
				{
					Vector2i mousePos = Mouse::getPosition(window);
					
					if (crearnuevo.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))){
						crearNuevoUsuario();
					}
				}
			}
		}
		
        window.clear(Color(63, 76, 171));
        window.draw(borde_superior);
        window.draw(lineaInfo_horizontal);
        window.draw(lineaOpc_horizontal);
        window.draw(texto_perfil);
        window.draw(nombre);
        window.draw(ultimaModificacion);
        window.draw(recuadroUsuario);
        window.draw(crearnuevo);
        window.draw(seleccionar);
        window.draw(borrar);

        window.display();
    }
    
}
