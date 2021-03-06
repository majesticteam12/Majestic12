// Majestic12.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
#include <string>
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "Renderer.h"
#define LOG(x) std::cout<<x;

int main()
{
	window Window("Majestic", 1280, 780);
	glClearColor(0.0f, 0.5f, 1.0f, 0.8f);

	Renderer renderer;
	
	if (glewInit() != GLEW_OK) {
		LOG("GLEW failed!");
	}

	float positions[6] = { -0.5f, -0.5f, 0.0f,0.5f, 0.5f, -0.5f };

	//Triangle buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2,0);

	//Shader
	Renderer::ShaderProgramSource source = renderer.ParseShader("Basic.shader");
	std::cout << source.vertexShader << std::endl;
	std::cout << source.fragmentShader << std::endl;

	while (!Window.Closed())
	{
		Window.Clear();
		/*glBegin(GL_POLYGON);
		glVertex2f(0,0.2f);
		glVertex2f(0.1, 0);
		glVertex2f(-0.1f,0);
		glVertex2f(0, -0.2f);
		glEnd();*/
		glDrawArrays(GL_TRIANGLES, 0, 3);
		Window.update();

	}

	
	return 0;
}


// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
