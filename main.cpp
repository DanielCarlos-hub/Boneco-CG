/*
GRUPO:
Daniel Carlos Soares
Marcos Oliveira
*/


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


// Declaração de variáveis globais
GLfloat tx = -5;
GLfloat ang1 = 180, ang2 = 0;
GLfloat win = 25;
GLfloat BracoEsquerdo = -190, AntBracoEsquerdo = 0, MaoEsquerda = -90;
GLfloat BracoDireito = -170, AntBracoDireito = 0, MaoDireita = -90;
GLfloat PernaDir = -180, CanelaDir = 0;
GLfloat PernaEsq = -180, CanelaEsq = 0;

// Função para desenhar um "braço" do boneco
void DesenhaBraco()
{

	glBegin(GL_QUADS);
		glVertex2f(0.5,3.0);
		glVertex2f(0.5,-1.0);
		glVertex2f(-0.5,-1.0);
		glVertex2f(-0.5,3.0);
	glEnd();
}

/*Função para desenhar o corpo do boneco */
void DesenhaCorpo()
{

	glBegin(GL_QUADS);
        glVertex2f(5.0,1.0);
        glVertex2f(1.2,1.0);
        glVertex2f(1.2,5.0);
        glVertex2f(5.0,5.0);
	glEnd();
}

void desenhacabeca(){

	glBegin(GL_QUADS);
        glVertex2f(3.0,0.5); //Canto inferior direito
        glVertex2f(1.0,0.5); //Canto superior esquerdo
        glVertex2f(1.0,2.0); //Canto superior esquerdo
        glVertex2f(3.0,2.0); //Canto superior direito
    glEnd();
}

void desenhaCabelo(){
    glBegin( GL_TRIANGLES );
		glVertex2f(-2.0f, 2.5f);
		glVertex2f(  0.0f,8.5f);
		glVertex2f( 2.0f, 2.5f);
    glEnd();

}

void desenhaPescosso(){

	glBegin(GL_QUADS);
        glVertex2f(3.0,0.5); //Canto inferior direito
        glVertex2f(1.0,0.5); //Canto superior esquerdo
        glVertex2f(1.0,2.0); //Canto inferior esquerdo
        glVertex2f(3.0,2.0); //Canto superior direito
    glEnd();
}

void desenhaOlhos(){

	glBegin(GL_QUADS);
        glVertex2f(3.0,0.5); //Canto inferior direito
        glVertex2f(1.0,0.5); //Canto superior esquerdo
        glVertex2f(1.0,2.0); //Canto inferior esquerdo
        glVertex2f(3.0,2.0); //Canto superior direito
    glEnd();
}

void desenhaChao(){
    glBegin( GL_QUADS );
        glVertex2f( 0, 0 );
        glColor3f(0.72f,0.45f,0.20f);
        glVertex2f( 0, 1 );
        glColor3f(0.5f, 0.35f, 0.05f);
        glVertex2f( 1, 1 );
        glColor3f(1.0f,0.78f,0.48f);
        glVertex2f( 1, 0 );
        glColor3f(0.72f,0.45f,0.20f);
    glEnd();
}

void desenhaRoupa(){
    glBegin( GL_TRIANGLES );
		glVertex2f(-2.0f, 2.5f);
		glVertex2f(  0.0f,8.5f);
		glVertex2f( 2.0f, 2.5f);
    glEnd();
}

void desenhaFundo(){
    glBegin( GL_QUADS );
        glColor3f(0.560784f, 0.560784f, 0.737255f);
        glVertex2f( 0, 0 );
        glVertex2f( 0, 1 );
        glVertex2f( 1, 1 );
        glVertex2f( 1, 0 );
    glEnd();

}

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
	// Muda para o sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa a matriz de transformação corrente
	glLoadIdentity();

	// Limpa a janela de visualização com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Desenha o "chão" a linha/
	glColor3f(0.0f,0.0f,0.0f);
	glLineWidth(4);
	glBegin(GL_LINES);
		glVertex2f(-win,-6.7);
		glVertex2f(win,-6.7);
	glEnd();

    /*Fundo*/
    glPushMatrix();
        glTranslatef(-50.0f, -6.55f,0.0f);
        glScalef(100.0f,100.0f,0.0f);
        desenhaFundo();
    glPopMatrix();

    /* Chão */ //quadrado
    glPushMatrix();
        glTranslatef(-50.0f,-25.0f,0.0f);
        glScalef(100.0f,18.2f,0.0f);
        desenhaChao();
    glPopMatrix();

    // Movimentação
	glTranslatef(tx,0.0f,0.0f);

    /*corpo*/
	glPushMatrix();
        glTranslatef(2.2f,-1.0f,0.0f);
        glScalef(1.5f,2.7f,1.0f);
        glColor3f(0.0f,0.0f,0.0f);
        DesenhaCorpo();
	glPopMatrix();


    /*roupa*/
	glPushMatrix();
        glTranslatef(6.8f,15.0f,0.0f);
        glRotatef(180.0f,0.0f,0.0f,1.0f);
        glColor3f(1.0f,0.0f,1.0f);
        desenhaRoupa();
	glPopMatrix();


    /*cabeça*/
	glPushMatrix();
        glColor3f(1.0f,0.75f,0.35f);
        glScalef(2.2f,2.5f,1.0f);
        glTranslatef(1.1f,5.0f,0.0f);
        desenhacabeca();
	glPopMatrix();

	/*cabelo*/
	glPushMatrix();
        glColor3f(1.0f,0.0f,0.35f);
        glScalef(0.3f,0.5f,1.0f);
        glTranslatef(17.5f,32.5f,0.0f);
        desenhaCabelo();

        glScalef(1.3f,1.0f,1.0f);
        glTranslatef(2.0f,0.0f,0.0f);
        desenhaCabelo();

        glScalef(1.3f,1.0f,1.0f);
        glTranslatef(2.0f,0.0f,0.0f);
        desenhaCabelo();

        glScalef(1.0f,1.0f,1.0f);
        glTranslatef(1.7f,0.0f,0.0f);
        desenhaCabelo();
    glPopMatrix();

    /*pescoço*/
	glPushMatrix();
        glColor3f(1.0f,0.75f,0.35f);
        glScalef(0.5f,1.5f,1.0f);
        glTranslatef(11.5f,7.8f,0.0f);
        desenhaPescosso();
	glPopMatrix();


	glPushMatrix();
        /*olhos*/
        glColor3f(0.0f,0.0f,0.0f);
        glScalef(0.3f,0.3f,1.0f);
        glTranslatef(17.5f,53.5f,0.0f);
        desenhaOlhos();
        /*olhos*/
        glTranslatef(5.5f, 0.0f,0.0f);
        glColor3f(0.0f,0.0f,0.0f);
        desenhaOlhos();
        /*nariz*/
        glTranslatef(-1.9f, -3.0f,0.0f);
        glScalef(0.7f,0.6f,1.0f);
        glColor3f(0.0f,0.0f,0.0f);
        desenhaOlhos();
        /*boca*/
        glTranslatef(-7.0f, -4.99f,0.0f);
        glScalef(4.3f,1.4f,1.0f);
        glColor3f(0.0f,0.0f,0.0f);
        desenhaOlhos();
	glPopMatrix();


	/*perna esquerda*/
    glPushMatrix();

        glColor3f(0.0f,0.0f,0.0f);

        glTranslatef(5.4f,1.3f,0.0f);
        glRotatef(PernaEsq,0.0f,0.0f,1.0f);
        glScalef(1.0f,1.5f,1.0f);
        DesenhaBraco();

        glTranslatef(0.0f,2.3f,0.0f);
        glScalef(1.0f,0.99f,1.0f);
        glRotatef(CanelaEsq,0.0f,0.0f,1.0f);
        DesenhaBraco();

    glPopMatrix();

    /*perna direita*/
    glPushMatrix();

        glColor3f(0.0f,0.0f,0.0f);

        glTranslatef(8.6f,1.3f,0.0f);
        glRotatef(PernaDir,0.0f,0.0f,1.0f);
        glScalef(1.0f,1.5f,1.0f);
        DesenhaBraco();

        glTranslatef(0.0f,2.3f,0.0f);
        glScalef(1.0f,0.99f,1.0f);
        glRotatef(CanelaDir,0.0f,0.0f,1.0f);
        DesenhaBraco();

    glPopMatrix();

    /*braço esquerdo*/
    glPushMatrix();

        glColor3f(0.0f,0.0f,0.0f);

        glTranslatef(4.0f,11.0f,0.0f);
        glRotatef(BracoEsquerdo,0.0f,0.0f,1.0f);
        glScalef(0.8f,1.2f,1.0f);
        DesenhaBraco();

        glTranslatef(0.0f,2.5f,0.0f);
        glRotatef(AntBracoEsquerdo,0.0f,0.0f,1.0f);
        glScalef(0.8f,1.2f,1.0f);
        DesenhaBraco();

        glColor3f(1.0f,0.75f,0.35f);
        glTranslatef(0.0f,2.5f,0.0f);
        glRotatef(MaoEsquerda,0.0f,0.0f,1.0f);
        glScalef(0.8f,0.4f,1.0f);
        DesenhaBraco();

    glPopMatrix();

    /*braço direito*/
    glPushMatrix();

        glColor3f(0.0f,0.0f,0.0f);

        glTranslatef(9.65f,11.0f,0.0f);
        glRotatef(BracoDireito,0.0f,0.0f,1.0f);
        glScalef(0.8f,1.2f,1.0f);
        DesenhaBraco();

        glTranslatef(0.0f,2.5f,0.0f);
        glRotatef(AntBracoDireito,0.0f,0.0f,1.0f);
        glScalef(0.8f,1.2f,1.0f);
        DesenhaBraco();

        glColor3f(1.0f,0.75f,0.35f);
        glTranslatef(0.0f,2.5f,0.0f);
        glRotatef(MaoDireita,0.0f,0.0f,1.0f);
        glScalef(0.8f,0.4f,1.0f);
        DesenhaBraco();

    glPopMatrix();
	glFlush();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior,
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura)
	{
		gluOrtho2D (-25.0f, 25.0f, -25.0f*altura/largura, 25.0f*altura/largura);
		win = 25.0f;
	}
	else
	{
		gluOrtho2D (-25.0f*largura/altura, 25.0f*largura/altura, -25.0f, 25.0f);
		win = 25.0f*largura/altura;
	}
}

// Função callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
void TeclasEspeciais(int key, int x, int y)
{
	// Move a base
	if(key == GLUT_KEY_LEFT)
	{
		tx-=0.2; //movimenta o boneco
		if ( tx < -win ) //limita a movimentação para não ultrapassar a window
			tx = -win;
        /* Movimenta o braco esquerdo enquanto o boneco se move para a esquerda */
        BracoEsquerdo -=1;
         if ( BracoEsquerdo < -196 )
			 BracoEsquerdo = -190 ;
        /* Movimenta o braco direito enquanto o boneco se move para a esquerda */
        BracoDireito+=1;
        if ( BracoDireito > -164 )
			 BracoDireito = -170 ;
        /* Movimento das pernas enquanto o boneco move para a esquerda */
        PernaEsq-=2;
        if ( PernaEsq < -240 )
			 PernaEsq = -240;
        PernaDir-=2;
        if ( PernaDir < -220 )
			 PernaDir = -220 ;
        /* Deslocamento das canelas enquanto o boneco move para a esquerda */
        CanelaEsq+=5;
        CanelaDir+=2;
        if ( CanelaEsq > 30){
			 CanelaEsq = 0;
			 PernaEsq = -180;
			 CanelaDir = 0;
			 PernaDir = -180;
        }
	}
	if(key == GLUT_KEY_RIGHT)
	{
		tx+=0.2;
		if ( tx > win )
			tx = win;
        /* Movimenta o braco esquerdo enquanto o boneco se move para a direita */
        BracoEsquerdo -=1;
         if ( BracoEsquerdo < -196 )
			 BracoEsquerdo = -190 ;
        /* Movimenta o braco direito enquanto o boneco se move para a direita */
        BracoDireito+=1;
        if ( BracoDireito > -164 )
			 BracoDireito = -170 ;
        /* Movimento das pernas enquanto o boneco move para a direita */
        PernaDir+=2;
        if ( PernaDir < -190 )
			 PernaDir = -190 ;
        PernaEsq+=2;
        if ( PernaEsq < -200 )
			 PernaEsq = -200;

        CanelaDir-=5;
        CanelaEsq-=2;
        if ( CanelaDir < - 30){
             CanelaDir = 0;
             PernaDir = -180;
             CanelaEsq = 0;
			 PernaEsq = -180;
        }
	}

    /*MOVIMENTA OS BRAÇOS PARA CIMA*/
    if(key == GLUT_KEY_UP){
        BracoEsquerdo-=5;
        if ( BracoEsquerdo < -350 )
			 BracoEsquerdo = -350 ;
        BracoDireito+=5;
        if ( BracoDireito > -10 )
			 BracoDireito = -10 ;
    }
    /*MOVIMENTA OS BRAÇOS PARA BAIXO*/
    if(key == GLUT_KEY_DOWN){
        BracoEsquerdo+=5;
        if ( BracoEsquerdo > -190 )
			 BracoEsquerdo = -190 ;
        BracoDireito-=5;
        if ( BracoDireito < -170 )
			 BracoDireito = -170 ;
    }
    /*MOVIMENTA O ANTIBRAÇO DIREITO E ESQUERDO EM ANTI-HORARIO */
    if(key == GLUT_KEY_PAGE_UP){
        AntBracoDireito-=5;
        if ( AntBracoDireito < -90)
			 AntBracoDireito =  -90;
        AntBracoEsquerdo+=5;
         if (AntBracoEsquerdo > 90)
			 AntBracoEsquerdo =  90;
    }
    /*MOVIMENTA O ANTIBRAÇO DIREITO E ESQUERDO NO SENTIDO HORARIO*/
    if(key == GLUT_KEY_PAGE_DOWN){
        AntBracoDireito+=5;
        if ( AntBracoDireito > 90)
			 AntBracoDireito = 90;
        AntBracoEsquerdo-=5;
        if ( AntBracoEsquerdo < -90)
			 AntBracoEsquerdo = -90;
    }

    /*MOVIMENTA O BRAÇO ESQUERDO SENTIDO HORARIO E ANTIHORARIO COM LIMITE SUPERIOR DE -350 GRAUS E INFERIOR DE -190 GRAUS*/
    if(key == GLUT_KEY_F1)
        BracoEsquerdo -=5;
         if ( BracoEsquerdo < -350 )
			 BracoEsquerdo = -350 ;

    if(key == GLUT_KEY_F2)
        BracoEsquerdo+=5;
        if ( BracoEsquerdo > -190 )
			 BracoEsquerdo = -190 ;

    /*MOVIMENTA O BRAÇO DIREITO SENTIDO HORARIO E ANTIHORARIO COM LIMITE SUPERIOR DE -10 GRAUS E INFERIOR DE -170 GRAUS*/
    if(key == GLUT_KEY_F3)
        BracoDireito+=5;
        if ( BracoDireito > -10 )
			 BracoDireito = -10 ;
    if(key == GLUT_KEY_F4)
        BracoDireito-=5;
        if ( BracoDireito < -170 )
			 BracoDireito = -170 ;

    /*MOVIMENTA O ANTEBRAÇO ESQUERDO SENTIDO HORARIO E ANTIHORARIO COM LIMITE SUPERIOR DE -90 GRAUS E INFERIOR DE 90 GRAUS*/
    if(key == GLUT_KEY_F5)
        AntBracoEsquerdo-=5;
        if ( AntBracoEsquerdo <-90)
			 AntBracoEsquerdo = -90;
    if(key == GLUT_KEY_F6)
        AntBracoEsquerdo+=5;
         if (AntBracoEsquerdo > 90)
			 AntBracoEsquerdo =  90;

    /*MOVIMENTA O ANTEBRAÇO ESQUERDO SENTIDO HORARIO E ANTIHORARIO COM LIMITE SUPERIOR DE 90 GRAUS E INFERIOR DE 90 GRAUS*/
    if(key == GLUT_KEY_F7)
        AntBracoDireito-=5;
        if ( AntBracoDireito < -90)
			 AntBracoDireito =  -90;
    if(key == GLUT_KEY_F8)
        AntBracoDireito+=5;
         if ( AntBracoDireito > 90)
			 AntBracoDireito = 90;


    /*MOVIMENTA A PERNA ESQUERDA NO SENTIDO HORARIO E ANTIHORARIO COM LIMITE SUPERIOR DE -210 GRAUS E INFERIOR DE -160 GRAUS*/
    if(key == GLUT_KEY_F9)
        PernaEsq-=5;
         if ( PernaEsq < -210 )
			 PernaEsq = -210;
    if(key == GLUT_KEY_F10)
        PernaEsq+=5;
        if ( PernaEsq > -160 )
			 PernaEsq = -160;

    /*MOVIMENTA A PERNA DIREITA NO SENTIDO HORARIO E ANTIHORARIO COM LIMITE SUPERIOR DE -210 GRAUS E INFERIOR DE -160 GRAUS*/
    if(key == GLUT_KEY_F11)
        PernaDir-=5;
         if ( PernaDir < -210 )
			 PernaDir = -210 ;
    if(key == GLUT_KEY_F12)
        PernaDir+=5;
         if ( PernaDir > -160 )
			 PernaDir = -160;


/* MOVIMENTA A MAO DIREITA*/
    if(key == GLUT_KEY_END)
        MaoDireita+=5;
        if ( MaoDireita > 90)
			 MaoDireita = 90;
    if(key == GLUT_KEY_HOME)
        MaoDireita-=5;
        if ( MaoDireita < -90)
			 MaoDireita = -90;
/* MOVIMENTA CANELA ESQUERDA
    if(key == GLUT_KEY_PAGE_UP)
        CanelaEsq-=5;
        if ( CanelaEsq < 0)
			CanelaEsq = 0;
    if(key == GLUT_KEY_PAGE_DOWN)
        CanelaEsq+=5;
        if ( CanelaEsq > 90)
			 CanelaEsq = 90;*/
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
    if (key == 97){
        CanelaEsq+=5;
        if ( CanelaEsq > 7)
			 CanelaEsq = 7;
        PernaEsq+=5;
        if ( PernaEsq > -160)
             PernaEsq = -160;
    }
    if (key == 100){
        CanelaEsq-=5;
        if ( CanelaEsq < 10)
             CanelaEsq = 10;
        PernaEsq-=5;
        if ( PernaEsq < -210)
             PernaEsq = -210;
    }
    glutPostRedisplay();
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}

// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(1366,768);
	glutCreateWindow("Trabalho Prático: Movimentos de Braços, Pernas, AnteBraços e Coxas / GRUPO: Daniel Carlos e Marcos Oliveira");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);

	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a função callback para tratamento das teclas especiais
	glutSpecialFunc(TeclasEspeciais);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Chama a função responsável por fazer as inicializações
	Inicializa();

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}
