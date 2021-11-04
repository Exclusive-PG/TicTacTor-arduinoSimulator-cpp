#pragma once
#include "./parserCMD.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
#pragma comment ( lib, "ws2_32.lib" )
#include <stdio.h>
#include <winsock2.h>
#include <typeinfo>
#include <iostream>
#include <exception>
#include <string>
#include <locale.h>
#include <Windows.h>
#include <thread> 
#include "graphics.h"
#include <iomanip>     
#include <ctime> 
#include <time.h>
#include "./GraphicsLib.h"
#include "./ArduinoSimulator.h"
#include "TicTacToe.h"
#define PORT 7777 
#define PI 3.14159265359

namespace UDPCLRCLIENT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	char* commandServer(int* buff, int bfsize);
	parserCMD ParserCommands;
	GraphicsLib graphicsLib;
	SOCKET Socket;
	char buff[1024] = "Server";
	sockaddr_in local_addr;
	sockaddr_in client_addr;
	HOSTENT* hst;
	char* ANSWER_ ;
	string ANSWER____;
	ArduinoSimulator arduino;
	bool LCDBOOL = false;
	char* localBuff;
	char bufTIME[80];
	public struct StatusClock {
		bool isStarting = true;
	};

	StatusClock SC;
	TicTacToe gameArduino;
	const int WIDTH = 1000, HEIGHT = 600;
	const int RADIUS = 300;
	const int X = WIDTH / 2, Y = HEIGHT / 2;

	const int HOUR_DIVISIONS = 12, MINUTE_DIVISIONS = 60, SECOND_DIVISIONS = 60;
	const double HOUR_SECTION = 2 * PI / HOUR_DIVISIONS;
	const double MINUTE_SECTION = 2 * PI / MINUTE_DIVISIONS;
	const double SECOND_SECTION = 2 * PI / SECOND_DIVISIONS;





public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();


		
			myThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ServerUDPActive));
			CheckStatus = gcnew Thread(gcnew ThreadStart(this, &MyForm::CheckStatusAnswer));
			ServerStatus = gcnew Thread(gcnew ThreadStart(this, &MyForm::startServerStatus));
		//	MatrixDiodAnimation = gcnew Thread(gcnew ThreadStart(this, &MyForm::TicTacToeDiodMatrix));
			//DigitalClock = gcnew Thread(gcnew ThreadStart(this, &MyForm::drawDigitalClock));

			//DigitalClock->IsBackground = true;
			ServerStatus->IsBackground = true;
			myThread->IsBackground = true;
			//MatrixDiodAnimation->IsBackground = true;
			//MatrixDiodAnimation->Start();
			CheckStatus->Start();
			myThread->Start();
		
			   ServerStatus->Start();
			//DigitalClock->Start();
			//CREATE WINDOW

			graphicsLib.initWINDOW(WIDTH, HEIGHT);
			DrawLCD();
			
			
			gameArduino.drawMap();
			
			//if (gameArduino.arrayField[0][1] == 2) {
			//	graphicsLib.DrawCircle(100, 100,50,255,255,255);
			//}
		}

	public:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox17;
	private: System::Windows::Forms::PictureBox^ pictureBox18;




	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::PictureBox^ pictureBox13;
	private: System::Windows::Forms::PictureBox^ pictureBox14;
	private: System::Windows::Forms::PictureBox^ pictureBox15;
	private: System::Windows::Forms::PictureBox^ pictureBox19;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;







	private: System::Windows::Forms::PictureBox^ pictureBox16;

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox9;

	


		  
	






	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(49, 30);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(133, 165);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 0;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(49, 375);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(133, 165);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 6;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(347, 30);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(133, 165);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 7;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(199, 375);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(133, 165);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 8;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(347, 375);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(133, 165);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 9;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(199, 30);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(133, 165);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(581, 255);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(494, 169);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 11;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(531, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(387, 151);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 12;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(49, 201);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(133, 165);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox10->TabIndex = 13;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Click += gcnew System::EventHandler(this, &MyForm::pictureBox10_Click);
			// 
			// pictureBox17
			// 
			this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.Image")));
			this->pictureBox17->Location = System::Drawing::Point(199, 201);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(133, 165);
			this->pictureBox17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox17->TabIndex = 14;
			this->pictureBox17->TabStop = false;
			this->pictureBox17->Click += gcnew System::EventHandler(this, &MyForm::pictureBox17_Click);
			// 
			// pictureBox18
			// 
			this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.Image")));
			this->pictureBox18->Location = System::Drawing::Point(347, 201);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(133, 165);
			this->pictureBox18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox18->TabIndex = 15;
			this->pictureBox18->TabStop = false;
			this->pictureBox18->Click += gcnew System::EventHandler(this, &MyForm::pictureBox18_Click);
			// 
			// pictureBox19
			// 
			this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.Image")));
			this->pictureBox19->Location = System::Drawing::Point(952, 12);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(101, 152);
			this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox19->TabIndex = 16;
			this->pictureBox19->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(960, 175);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 20);
			this->label2->TabIndex = 18;
			this->label2->Text = L"DisplayDiod";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(706, 175);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 20);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Display";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(212, 3);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 24);
			this->label5->TabIndex = 21;
			this->label5->Text = L"TicTacToe";
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(1107, 573);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox19);
			this->Controls->Add(this->pictureBox18);
			this->Controls->Add(this->pictureBox17);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
		//red - 1
		//yellow -2
		//green - 3
		// 
			void checkArduinoSystem() {
				//Red
				this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.HIGH)));
				this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.HIGH)));
				delay(1000);
				this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(2, 10, arduino.HIGH)));
				this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(2, 10, arduino.HIGH)));
				delay(1000);
				this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.HIGH)));
				this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.HIGH)));
				delay(1000);
				this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.LOW)));
				this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.LOW)));
				this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.LOW)));
				this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.LOW)));
				this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(2, 10, arduino.LOW)));
				this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(2, 10, arduino.LOW)));
		}

		void RedDiod(int msDelay) {
		//	this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.HIGH)));
		//	delay(msDelay);
			//this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.LOW)));
		}

		void YellowDiod(int msDelay) {
			this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 11, arduino.HIGH)));
			delay(msDelay);
			this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 11, arduino.LOW)));
		}

		void GreenDiod(int msDelay) {
			this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.HIGH)));
			delay(msDelay);
			this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.LOW)));
		}
		void RedDiod2(int msDelay) {
			this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 13, arduino.HIGH)));
			delay(msDelay);
			this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 13, arduino.LOW)));
		}

		void YellowDiod2(int msDelay) {
			this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 14, arduino.HIGH)));
			delay(msDelay);
			this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 15, arduino.LOW)));
		}

		void GreenDiod2(int msDelay) {
			this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(3, 16, arduino.HIGH)));
			delay(msDelay);
			this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(3, 16, arduino.LOW)));
		}
		void DiodLCD(int msDelay,bool onOff) {
			if (onOff) {
				LCDBOOL = onOff;
					this->pictureBox19->Load(gcnew System::String(arduino.digitalWrite(1, 8, arduino.HIGH)));
					delay(100);
					this->pictureBox19->Load(gcnew System::String(arduino.digitalWrite(1, 8, arduino.LOW)));
					delay(100);
					this->pictureBox19->Load(gcnew System::String(arduino.digitalWrite(1, 8, arduino.HIGH)));
					delay(100);
					this->pictureBox19->Load(gcnew System::String(arduino.digitalWrite(1, 8, arduino.LOW)));
					delay(100);
					this->pictureBox19->Load(gcnew System::String(arduino.digitalWrite(1, 8, arduino.HIGH)));
					
				
			}
			else {
				LCDBOOL = onOff;
				this->pictureBox19->Load(gcnew System::String(arduino.digitalWrite(1, 16, arduino.LOW)));
			}
		}

		bool MATRIX_ON_OFF ;
		//void MatrixDiodAnimFunc() {
			//int delayInt = 500;
			//while (true) {
			//	if (MATRIX_ON_OFF) {
			//		this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.HIGH)));
			//		delay(delayInt);
			//		this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 11, arduino.HIGH)));
			//		delay(delayInt);
			//		this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.HIGH)));
			//		delay(delayInt);
			//		this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(3, 16, arduino.HIGH)));
			//		delay(delayInt);
			//		this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 14, arduino.HIGH)));
			//		delay(delayInt);
			//		this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 13, arduino.HIGH)));
			//		delay(delayInt);

			//		this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 13, arduino.LOW)));
			//		delay(delayInt);
			//		this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 14, arduino.LOW)));
			//		delay(delayInt);
			//		this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(3, 16, arduino.LOW)));
			//		delay(delayInt);
			//		this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.LOW)));
			//		delay(delayInt);
			//		this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 11, arduino.LOW)));
			//		delay(delayInt);
			//		this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.LOW)));
			//		delay(delayInt);

			//		delayInt -= 100;

			//		if (delayInt == 100) delayInt = 500;
			//	}
			//	else {
			//	

			//		try
			//		{

			//			this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 13, arduino.LOW)));
			//			//	delay(1000);
			//			this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 14, arduino.LOW)));
			//			//delay(1000);
			//			this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(3, 16, arduino.LOW)));
			//			//	delay(1000);
			//			this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.LOW)));
			//			//	delay(1000);
			//			this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 11, arduino.LOW)));
			//			//	delay(1000);
			//			this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.LOW)));
			//		}

			//		catch (const std::exception& ex)
			//		{
			//			delay(5000);
			//		}
			//		
			//		delay(5000);
			//	}
			//}
		//}
		void DrawLCD() {
			int step = 20;
			//79, 163, 107
			graphicsLib.FillRectangle(200, 150, 850, 550, 2, 28, 99);
			//52,52,52
			graphicsLib.FillRectangle(230, 170, 770, 530, 255,255,255);
			//29,42,72
			graphicsLib.FillRectangle(240, 180, 760, 520, 0,0,0);
			//graphicsLib.FillRectangle(,);
			graphicsLib.DrawRectangle(800, 190, 840, 420,255,255,255);
			for (size_t i = 0; i < 9; i++)
			{
			
				graphicsLib.FillCircle(830, 200 + step, 5, 255, 255, 255);
				step += 20;
			}
			
			step = 20;
			for (size_t i = 0; i < 9; i++)
			{

				graphicsLib.FillCircle(810, 200 + step, 5, 255, 255, 255);
				step += 20;
			}
		}

		void getDataArduino() {
			RedDiod(1000);
			

			YellowDiod(1000);
			

			GreenDiod(1000);


			RedDiod2(1000);


			YellowDiod2(1000);


			GreenDiod2(1000);
			
		}

		void lcdDrawCircles() {
			int step = 30;
			for (size_t i = 0; i < 15; i++)
			{
				graphicsLib.FillCircle(250 + step, 380, 15, 255, 255, 255);
				delay(500);
				step += 30;
			}
			step -= 30;
			for (size_t i = 15; i > 0 ; i--)
			{
				
				graphicsLib.FillCircle(250 + step, 380, 15, 29, 42, 72);
				delay(500);
				step -= 30;
			}
			
	}
		void lcdDrawRectangles(int msDelay) {
			int step = 30;
			int maxStep = 0;
			int temp;
			for (size_t i = 0; i < 11; i++)
			{
				step += 10;
				graphicsLib.FillRectangle(250+step , 340, 280 + step,380, 255, 255, 255);
				delay(msDelay);
				step += 30;
				
			}
		
			step = 30;
			for (size_t i = 0; i < 11; i++)
			{
				step += 10;
				graphicsLib.FillRectangle(250 + step, 390, 280 + step, 430, 255, 255, 255);
				delay(msDelay);
				step += 30;
			}
			int step1 = 380;
			int step2 = 420;
			for (size_t i = 12; i > 0; i--)
			{
				
				graphicsLib.FillRectangle(250 + step1, 340, 280 + step2, 380, 255, 255, 255);
				delay(msDelay);
				step1 -= 30;
				step2 -= 30;
			}

			 step1 = 380;
			 step2 = 420;
			for (size_t i = 12; i > 0; i--)
			{
				
				graphicsLib.FillRectangle(250 + step1, 390, 280  + step2, 430, 255, 255, 255);
				delay(msDelay);
				step1 -= 30;
				step2 -= 30;
			}

		}

	
		void refreshDiods() {
		this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 13, arduino.LOW)));
						
		this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 14, arduino.LOW)));
						
		this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(3, 16, arduino.LOW)));
						
		this->pictureBox10->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.LOW)));
					
		this->pictureBox17->Load(gcnew System::String(arduino.digitalWrite(2, 11, arduino.LOW)));
						
		this->pictureBox18->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.LOW)));

		this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(3, 12, arduino.LOW)));

		this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 11, arduino.LOW)));

		this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 10, arduino.LOW)));

		}


		void TicTacToeDiods() {
			//while (1) {
				for (size_t i = 0; i < sizeof(gameArduino.arrayField) / sizeof(*gameArduino.arrayField); i++)
				{
					for (size_t j = 0; j < sizeof(gameArduino.arrayField) / sizeof(*gameArduino.arrayField); j++)
					{
						delay(1000);
						graphicsLib.DrawText(10, 150, 0, 10, 255, 255, 255, to_string(i) + "|" + to_string(i));
						if (gameArduino.arrayField[i][j] == gameArduino.PlayerNum) {

							switch (gameArduino.getStep(i, j)) {

							case 1:
								this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 2, arduino.HIGH)));
								break;
							case 2:
								this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(1, 3, arduino.HIGH)));
								break;
							case 3:
								this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(1, 4, arduino.HIGH)));
								break;
							case 4:
								this->pictureBox10->Load(gcnew System::String(arduino.digitalWrite(1, 5, arduino.HIGH)));
								break;
							case 5:
								this->pictureBox17->Load(gcnew System::String(arduino.digitalWrite(1, 6, arduino.HIGH)));
								break;
							case 6:
								this->pictureBox18->Load(gcnew System::String(arduino.digitalWrite(1, 7, arduino.HIGH)));
								break;
							case 7:
								this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(1, 8, arduino.HIGH)));
								break;
							case 8:
								this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(1, 9, arduino.HIGH)));
								break;
							case 9:
								this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 12, arduino.HIGH)));
								break;
							}
							graphicsLib.DrawText(10, 10, 0, 10, 255, 255, 255, to_string(gameArduino.getStep(i, j)));

						}
						
						else if (gameArduino.arrayField[i][j] == gameArduino.CPUNum) {
							switch (gameArduino.getStep(i, j)) {

							case 1:
								this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(2, 2, arduino.HIGH)));
								break;
							case 2:
								this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 3, arduino.HIGH)));
								break;
							case 3:
								this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(2, 4, arduino.HIGH)));
								break;
							case 4:
								this->pictureBox10->Load(gcnew System::String(arduino.digitalWrite(2, 5, arduino.HIGH)));
								break;
							case 5:
								this->pictureBox17->Load(gcnew System::String(arduino.digitalWrite(2, 6, arduino.HIGH)));
								break;
							case 6:
								this->pictureBox18->Load(gcnew System::String(arduino.digitalWrite(2, 7, arduino.HIGH)));
								break;
							case 7:
								this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(2, 8, arduino.HIGH)));
								break;
							case 8:
								this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 9, arduino.HIGH)));
								break;
							case 9:
								this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(2, 12, arduino.HIGH)));
								break;
							}
							graphicsLib.DrawText(10, 70, 0, 10, 255, 255, 255, to_string(gameArduino.getStep(i, j)));
						}


					}
				}
				delay(1000);
			//}
		}

		void TicTacToeDiodMatrix(int pos, int who) {

			if (who == gameArduino.PlayerNum) {

				switch (pos) {

				case 1:
					this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(1, 2, arduino.HIGH)));
					break;
				case 2:
					this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(1, 3, arduino.HIGH)));
					break;
				case 3:
					this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(1, 4, arduino.HIGH)));
					break;
				case 4:
					this->pictureBox10->Load(gcnew System::String(arduino.digitalWrite(1, 5, arduino.HIGH)));
					break;
				case 5:
					this->pictureBox17->Load(gcnew System::String(arduino.digitalWrite(1, 6, arduino.HIGH)));
					break;
				case 6:
					this->pictureBox18->Load(gcnew System::String(arduino.digitalWrite(1, 7, arduino.HIGH)));
					break;
				case 7:
					this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(1, 8, arduino.HIGH)));
					break;
				case 8:
					this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(1, 9, arduino.HIGH)));
					break;
				case 9:
					this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(1, 12, arduino.HIGH)));
					break;
				}


			}

			else if (who == gameArduino.CPUNum) {
				switch (pos) {

				case 1:
					this->pictureBox5->Load(gcnew System::String(arduino.digitalWrite(2, 2, arduino.HIGH)));
					break;
				case 2:
					this->pictureBox2->Load(gcnew System::String(arduino.digitalWrite(2, 3, arduino.HIGH)));
					break;
				case 3:
					this->pictureBox7->Load(gcnew System::String(arduino.digitalWrite(2, 4, arduino.HIGH)));
					break;
				case 4:
					this->pictureBox10->Load(gcnew System::String(arduino.digitalWrite(2, 5, arduino.HIGH)));
					break;
				case 5:
					this->pictureBox17->Load(gcnew System::String(arduino.digitalWrite(2, 6, arduino.HIGH)));
					break;
				case 6:
					this->pictureBox18->Load(gcnew System::String(arduino.digitalWrite(2, 7, arduino.HIGH)));
					break;
				case 7:
					this->pictureBox6->Load(gcnew System::String(arduino.digitalWrite(2, 8, arduino.HIGH)));
					break;
				case 8:
					this->pictureBox8->Load(gcnew System::String(arduino.digitalWrite(2, 9, arduino.HIGH)));
					break;
				case 9:
					this->pictureBox9->Load(gcnew System::String(arduino.digitalWrite(2, 12, arduino.HIGH)));
					break;
				}
				
			}

		}
	
			//}
		
#pragma endregion

	
		char* commandServer(int* arrayWord, int bfsize) {
			
			//checkArduinoSystem();
			char* answerTempGame;
			char AnswerChar[2048];
			char buffTime[2048];
			char* INPUT_ERROR = (char*)"Input Error";
			char* COMMAND_NOT_FOUND = (char*)"Command not found";
			char AnswerServer[100] = "OK";

			time_t     now ;
			struct tm  tstruct;

			cout << "CMD : " << (int)arrayWord[0] << endl;
			
			//graphicsLib.ClearDisplay();
			switch ((int)arrayWord[0]) {
				
				

			case ParserCommands.CLEAR_DISPLAY:
				GreenDiod(1000);
					
				graphicsLib.ClearDisplay();
				DrawLCD();
				return (char*)"Display cleared";
				break;

			case ParserCommands.DRAW_PIX:
				
				graphicsLib.drawPixel(arrayWord[1], arrayWord[2],arrayWord[3], arrayWord[4], arrayWord[5]);
				return (char*)"draw pix - success";
				break;
			case ParserCommands.DRAW_LINE:
				
				graphicsLib.drawLine(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6], arrayWord[7]);
	
				return (char*)"draw line - success";
				break;

				break;

			case ParserCommands.DRAW_REACTANGLE:
			
				graphicsLib.DrawRectangle(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6], arrayWord[7]);
				return (char*)"DRAW_REACTANGLE - success";


				break;
			case ParserCommands.FILL_REACTANGLE:
				
				graphicsLib.FillRectangle(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6], arrayWord[7]);
				return (char*)"FILL_REACTANGLE - success";
				break;

			case ParserCommands.DRAW_ELLIPSE:
				graphicsLib.DrawEllipse(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6], arrayWord[7]);
				return (char*)"DRAW_ELLIPSE - success";
				break;

			case ParserCommands.FILL_ELLIPSE:
				graphicsLib.FillEllipse(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6], arrayWord[7]);
				return (char*)"FILL_ELLIPSE - success";
				break;



			case ParserCommands.DRAW_CIRCLE:
				graphicsLib.DrawCircle(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6]);

				return (char*)"DRAW_CIRCLE - success";
	
				break;

			case ParserCommands.FILL_CIRCLE:
				graphicsLib.FillCircle(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6]);

				return (char*)"FILL_CIRCLE - success";
				break;

			case ParserCommands.DRAW_ROUND_RECTANGLE:

				return (char*)"DRAW_ROUND_RECTANGLE - success";
				break;
			case ParserCommands.FILL_ROUND_RECTANGLE:

				return (char*)"FILL_ROUND_RECTANGLE - success";
				break;
			case ParserCommands.DRAW_TEXT:
				cout << ParserCommands.TEXT << endl;
				graphicsLib.DrawText(arrayWord[1], arrayWord[2], arrayWord[3], arrayWord[4], arrayWord[5], arrayWord[6], arrayWord[7], ParserCommands.TEXT);
				return (char*)"DRAW_TEXT - success";
				break;

			case ParserCommands.DRAW_IMG:
				cout << ParserCommands.NAME_IMG << endl;
				//circle(100, 100, 50);
				//line(200, 200, 500, 500);
				//writeimagefile("image.bmp");
				//readimagefile("image.bmp", 0, 0, getwindowwidth(), getwindowheight());

				return (char*)"DRAW_IMG - success";
				break;

			case ParserCommands.SET_ORIN:
				graphicsLib.setOrin(arrayWord[1], arrayWord[2]);
				return (char*)"SET_ORIN - success";
				break;

			case ParserCommands.GET_WIDTH:

				sprintf(AnswerChar, "Width Display : %d\n", graphicsLib.getWindowWidth());

				return AnswerChar;

				break;

			case ParserCommands.GET_HEIGHT:


				sprintf(AnswerChar, "Height Display : %d\n", graphicsLib.getWindowHeight());

				return AnswerChar;
				break;
			
			case ParserCommands.GET_TIME:
		
				  now = time(0);
				 tstruct;
				

				tstruct = *localtime(&now);

				strftime(bufTIME, sizeof(bufTIME), "%d/%m/%Y", &tstruct);
				

				return bufTIME;
				break;

			case ParserCommands.START_TIME:

				SC.isStarting = true;
				
				return (char*)"Digital Clock is starting...";
				break;

			case ParserCommands.STOP_TIME:

				SC.isStarting = false;
				
				return (char*)"Digital Clock was stopped...";
				break;
			case ParserCommands.SET_PRESET_DC:

				SC.isStarting = false;
				delay(1000);
				
				graphicsLib.ClearDisplay();
				SC.isStarting = true;
				return (char*)"Preset found";
				break;

			case ParserCommands.PRESS_BTN_ONE_ARDUINO:
				GreenDiod(1000);
				checkArduinoSystem();
				return (char*)"arduino btn_pressed_one";
				break;

			case ParserCommands.PRESS_BTN_TWO_ARDUINO:
				GreenDiod(1000);
				getDataArduino();
				return (char*)"arduino btn_pressed_two\nLCD:connected\nX:350-700 Y:310-400\nLed(7):\nRedDiod - 2\nGreenDiod - 2\nYellowDiod - 2\n\nLCD diod -1";
				break;

			case ParserCommands.LCD_ON:
				GreenDiod(1000);
				DiodLCD(100,true);
				return (char*)"arduion Screen:on";
				break;
			case ParserCommands.LCD_OFF:
				GreenDiod(1000);
				DiodLCD(100, false);
				return (char*)"arduion Screen:off";
				break;
			case ParserCommands.PRESS_BTN_THREE_ARDUINO:
				GreenDiod(1000);
				if (LCDBOOL) {
					graphicsLib.DrawText(270, 340, 0, 10, 255, 255, 255, "Hello_World");
					return (char*)"arduino btn_pressed_three\nLCD draw - success";
				}
				else {
					return (char*)"arduino btn_pressed_three\nLCD draw - failed -> LCD : off";
				}
				return (char*)"arduion LCD:on";
				break;
			case ParserCommands.IDLE_ARDUINO:
				GreenDiod(1000);
				MATRIX_ON_OFF = true;
				return (char*)"idle arduino animation";
				break;
			case ParserCommands.STOP_IDLE_ARDUINO:
				GreenDiod(1000);
				MATRIX_ON_OFF = false;
				
				return (char*)"stop idle arduino animation";
				break;
				
			case ParserCommands.DRAW_LCD_CIRCLES:
				GreenDiod(1000);
				if (LCDBOOL) {
					lcdDrawCircles();
					return (char*)"LCD draw circles - success";
				}
				else {
					return (char*)"LCD - off \ndraw circles - failed";
				}

				
				break;
			
			case ParserCommands.DRAW_LCD_RECTANGLES:
				if (LCDBOOL) {
				lcdDrawRectangles(100);
				return (char*)"LCD draw rectangles - success";
				}
				else {
				return (char*)"LCD - off \ndraw rectangles - failed";
				}
				break;
			case ParserCommands.GAME_MOVE:
				if (LCDBOOL) {
						answerTempGame = gameArduino.moveField(arrayWord[2]);
					delay(1000);
					TicTacToeDiodMatrix(arrayWord[2], gameArduino.PlayerNum);
					TicTacToeDiodMatrix(gameArduino.cpuNumtemp, gameArduino.CPUNum);
					return answerTempGame;
				}
				else {
					return (char*)"Screen not turned on";
				}
				
					//delay(1000);
					//TicTacToeDiodMatrix();

				
				
				break;
			case ParserCommands.GAME_RESTART:
				refreshDiods();
				
				gameArduino.restart();
				DrawLCD();
				
				gameArduino.drawMap();
				//gameArduino.drawMap();
				//gameArduino.drawMap();
				break;
			case -999:
				YellowDiod(1000);
				
				return INPUT_ERROR;

			case 0:
				RedDiod(1000);
				return COMMAND_NOT_FOUND;
			}



			return AnswerServer;
		}


	

	
	

	
		void ServerUDPActive() {
			
			setlocale(LC_ALL, "Russian");

			// подключение библиотеки 
			if (WSAStartup(0x202, (WSADATA*)&buff[0]))
			{


			};

			// создание сокета

			Socket = socket(AF_INET, SOCK_DGRAM, 0);
			if (Socket == INVALID_SOCKET)
			{
				WSACleanup();

			};

			// связывание сокета с локальным адресом 

			local_addr.sin_family = AF_INET;
			local_addr.sin_addr.s_addr = INADDR_ANY;
			local_addr.sin_port = htons(PORT);

			if (bind(Socket, (sockaddr*)&local_addr, sizeof(local_addr)))
			{
				closesocket(Socket);
				WSACleanup();

			}else startServerStatus();
			
		
			// обработка пакетов, присланных клиентами
			while (1)
			{

				int client_addr_size = sizeof(client_addr);
				int bsize = recvfrom(Socket, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);

				// Получаем IP-адрес клиента 

				hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);
				printf("\n+%s [%s:%d] new message :", (hst) ? hst->h_name : "Unknown host", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

				// добавление завершающего нуля
				buff[bsize] = 0;

				ANSWER_ = commandServer(ParserCommands.parserV2(buff), bsize);
				localBuff = buff;
				this->Invoke(gcnew Action(this, &MyForm::CheckStatusAnswer));
				sendto(Socket, ANSWER_, sizeof(buff), 0, (sockaddr*)&client_addr, sizeof(client_addr));

			}

		}



		void CheckStatusAnswer() {
			//this->label1->Text = gcnew System::String(ANSWER_);

			time_t     now = time(0);
			struct tm  tstruct;
			char       buf[80];
			tstruct = *localtime(&now);
			
			strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

			for (size_t i = 0; i < 80; i++)
			{
				bufTIME[i] = buf[i];
			}

			string outputStr =  (char)" : " + buf;
					
			char* cstr = new char[outputStr.length() + 1];
			strcpy(cstr, outputStr.c_str());
		
			
			string outputRes = buff;

			//textBox1->Text += gcnew System::String(buf) + " : " + gcnew System::String(buff) + "\r\n";
			delete[] cstr;
		}
		void startServerStatus(){
			//this->label2->Text = "Server UDP is listening...";
		}


	private: Thread^ myThread;
	private: Thread^ CheckStatus;
	private: Thread^ ServerStatus;
	private: Thread^ DigitalClock;
    private: Thread^ MatrixDiodAnimation;






		 



private: System::Void pictureBox17_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) {
//	checkArduinoSystem();
}
private: System::Void pictureBox18_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
};


