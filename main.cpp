#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "HEADERS/VentanaAjustes_Header.h"
//#include "HEADERS/VentanaPerfil_Header.h"
#include "HEADERS/VentanaInfo_Header.h"

using namespace sf;
using namespace std;

class ControlMusica
{
	
	public:
		ControlMusica(const string&filepath)
		{
			if(!music.openFromFile(filepath))
			{
				system("echo No se pudo cargar el archivo de musica&pause");
			}
		}
		
		void play()
		{
			music.play();
		}
	
		void stop()
		{
			music.stop();
		}
		
		void loop()
		{
			music.setLoop(true);
		}
		
	
	private:
		Music music;
		
};

int main()
{
    // Creación de la ventana principal
    RenderWindow window(VideoMode(1000, 625), "Randy Python");
    
    ControlMusica control_musica("Audio/C_Fondo2.ogg");
    control_musica.play();
    control_musica.loop();
    
    Texture entrada1;
    
    if(!entrada1.loadFromFile("Entrada1.jpg"))
    {
    	system("echo No se pudo cargar la imagen de entrada&pause");
    	return EXIT_FAILURE;
	}
	
	Sprite sprite_entrada1(entrada1);
	
	sprite_entrada1.setScale(0.84f, 0.76f);
	
    
    Texture texture;
	Texture boton_jugar, boton_ajustes, boton_salir, boton_perfil, boton_info;
	Texture RandyPythonLetters;
    
    if (!texture.loadFromFile("Fondo-01.jpeg")){
    	system("echo No se pudo cargar la imagen&pause");
        return EXIT_FAILURE;
	}
	
	if (!boton_jugar.loadFromFile("Imagen/ButtonJugar.png")){
    	system("echo No se pudo cargar la imagen&pause");
        return EXIT_FAILURE;
	}
	
	if (!boton_ajustes.loadFromFile("Imagen/ButtonAjustes.png")){
		system("echo No se pudo cargar imagen de boton&pause");
		return EXIT_FAILURE;
	}
	
	if (!boton_salir.loadFromFile("Imagen/ButtonSalir.png")){
		system("echo No se pudo cargar imagen de salir&pause");
		return EXIT_FAILURE;
	}
	
	if (!boton_perfil.loadFromFile("Imagen/IconPerfil.png")){
		system("echo No se pudo cargar imagen de perfil&pause");
		return EXIT_FAILURE;
	}
	
	if (!boton_info.loadFromFile("Imagen/IconInfo.png")){
		system("echo No se pudo cargar imagen de salir&pause");
		return EXIT_FAILURE;
	}
	
	//Carga de los sprites para los botones
    Sprite sprite(texture);
	Sprite sprite_boton_jugar(boton_jugar), sprite_boton_ajustes(boton_ajustes), sprite_boton_salir(boton_salir);
	Sprite sprite_boton_perfil(boton_perfil), sprite_boton_info(boton_info);
    
    sprite.setTextureRect(IntRect(70, 300, 1100, 625));
    
    //Ajustando el tamaño del boton
    sprite_boton_ajustes.setScale(0.5f, 0.56f);
    sprite_boton_jugar.setScale(0.5f, 0.56f);
	sprite_boton_salir.setScale(0.5f, 0.5f); 
	sprite_boton_perfil.setScale(0.25f, 0.25f);
	sprite_boton_info.setScale(0.098f, 0.098f); 
	
    //Posicionar botones
    sprite_boton_jugar.setPosition(580, 115);
    sprite_boton_ajustes.setPosition(490, 260);
    sprite_boton_salir.setPosition(580, 400);
    sprite_boton_perfil.setPosition(90, 415);
    sprite_boton_info.setPosition(850, 285);
    
	if (!RandyPythonLetters.loadFromFile("Imagen/Randy Python Letters.png")){
		system("echo No se pudo cargar imagen de letras&pause");
		return EXIT_FAILURE;
	}
	
	Sprite SpriteRandyPythonLetters(RandyPythonLetters);
    //Ajustando el tamaño y la posicion de las letras randy pythom
    SpriteRandyPythonLetters.setScale(0.8f, 0.85f);
    SpriteRandyPythonLetters.setPosition(35, -140);
    
    Font font;
    if (!font.loadFromFile("Fuentes/SophiaFrancesca.ttf")){
    	system("echo No se pudo cargar la fuente&pause");
        return EXIT_FAILURE;
	}
    
    Text mensajeFullscreen("PULSA  LA  TECLA  F11  PARA  ENTRAR  EN  EL  MODO  FULLSCREEN", font, 12);
    mensajeFullscreen.setFillColor(Color(255, 255, 255, 180));
    mensajeFullscreen.setPosition(280, 560);
    
    
	//Carga del efecto de musica de cerrar
	Music fxCerrar;
	if(!fxCerrar.openFromFile("FX/Fx33.ogg"))
	{
		system("echo No se pudo cargar el audio de cerrar ventana&pause");
		return EXIT_FAILURE;
	}
	
	//Reloj para controlar el desvanecimiento de la entrada
	Clock clock;
	bool desvanecimiento1 = false;
	float alpha = 255.0f; //Valor inicial del alpha(transparencia)
	const float v_desvanecimiento1 = 30.0f;

    while (window.isOpen())
    {
        // Control de eventos
        Event event;
        while (window.pollEvent(event))
        {
        	
            if (event.type == Event::Closed)
                window.close();
                
			//Evento para controlar el boton salir
			if (event.type == Event::MouseButtonPressed){
				if(event.mouseButton.button == Mouse::Left){
					
					Vector2i mousePos = Mouse::getPosition(window);
					Vector2f woldPos = window.mapPixelToCoords(mousePos);
					
					if (sprite_boton_salir.getGlobalBounds().contains(woldPos)){
						window.close();
					}
				}
			}
            
			//Control de eventos para el desvanecimiento de la entrada    
            if(clock.getElapsedTime().asSeconds() > 0.5f)
            {
            	desvanecimiento1 = true;
			}
			
			if(desvanecimiento1)
			{
				float deltaTime = clock.restart().asSeconds();
				
				alpha -= v_desvanecimiento1 * deltaTime;
				
				if(alpha < 0.0f)
				{
					alpha = 0.0f;
				}
				
			sprite_entrada1.setColor(Color(255, 255, 255, static_cast<Uint8>(alpha)));
			}
			
			
            //Evento para controlar el fullscreen
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::F11){
            	window.close();
            	window.create(VideoMode::getDesktopMode(), "Randy Python debug_FullScreen", Style::Fullscreen);
			}
			
			//Evento para controlar el botón jugar e iniciar el juego
			if (event.type == Event::MouseButtonPressed){
				if(event.mouseButton.button == Mouse::Left){
					
					Vector2i mousePos = Mouse::getPosition(window);
					Vector2f woldPos = window.mapPixelToCoords(mousePos);
					
					if (sprite_boton_jugar.getGlobalBounds().contains(woldPos))
					{
						STARTUPINFO si = { sizeof(si)};
						
						si.dwFlags = STARTF_USESHOWWINDOW;
						si.wShowWindow = SW_HIDE;
						PROCESS_INFORMATION pi;
						
						control_musica.stop();
						
						if (CreateProcess("Randy Phantom Safeguard.exe", NULL, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
						{
							WaitForSingleObject(pi.hProcess, INFINITE);
							
							CloseHandle(pi.hProcess);
							CloseHandle(pi.hThread);
						}
						
						control_musica.play();
					}
				}
			}
			
			//Evento par acontrolar la ventana de ajustes
			if (event.type == Event::MouseButtonPressed){
				if(event.mouseButton.button == Mouse::Left){
					Vector2i mousePos = Mouse::getPosition(window);
					
					if (sprite_boton_ajustes.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))){
						ventana_ajustes();
						fxCerrar.play();
					}
				}
			}
			
			//Evento para controlar la ventana de perfil
			/*if (event.type == Event::MouseButtonPressed){
				if(event.mouseButton.button == Mouse::Left){
					Vector2i mousePos = Mouse::getPosition(window);
					
					if (sprite_boton_perfil.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))){
						music.setVolume(55);
						ventana_perfil();
						fxCerrar.play();
						music.setVolume(100);
					}
				}
			}*/
			
			//Envento para controlar la ventana de acerca de
			if (event.type == Event::MouseButtonPressed){
				if(event.mouseButton.button == Mouse::Left){
					Vector2i mousePos = Mouse::getPosition(window);
					
					if (sprite_boton_info.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))){
						//music.setVolume(55);
						ventana_info();
						fxCerrar.play();
						//music.setVolume(100);
					}
				}
			}
        }
        
        window.clear();
        
        //Bloque de dibujo
        window.draw(sprite);//Fondo
		window.draw(sprite_boton_jugar);
        window.draw(sprite_boton_ajustes);
        window.draw(sprite_boton_salir);
        window.draw(sprite_boton_info);
        window.draw(SpriteRandyPythonLetters);
        window.draw(mensajeFullscreen);
		
        if(alpha > 0.0f)//Manejador de la entrada
        {
        	window.draw(sprite_entrada1);
		}
		
        //Recarga de la ventana
        window.display();
    }
    return EXIT_SUCCESS;
}
