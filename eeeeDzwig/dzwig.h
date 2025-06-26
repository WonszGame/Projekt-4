#pragma once
#include <array>
#include <time.h>
#include <Windows.h>
#include <gdiplus.h>
#using <system.drawing.dll>
#using <System.dll>
#using<system.windows.forms.dll>
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref class MainForm : public Form{
private:
	bool firstTime = true;
    Button^ btnBottom;
    Button^ btnLeftTop;
    Button^ btnLeftMiddle;
    Button^ btnLeftLower;
    Button^ btnLeftBottom;

public:
    
    int hookX=0;
	int hookY=0;  
    bool objAttached=false;
    int objType=0;
    int towerProg = 0;
    array<int>^ cacheObject = gcnew array<int>(3);
	array <int>^ cacheWeight = gcnew array<int>(3);
    array<int>^ towerObjects = gcnew array<int>(3);
    
   

    void TowerInit() {
        for (int i = 0; i < 3; i++) {
			towerObjects[i] = 0; 
        }
    }
    

    void Reset(){
        hookX = 0;
        hookY = 0;
        objAttached = false;
        objType = 0;
        towerProg = 0;
		CacheSet();
	}

    void CacheSet() {
        Random^ rand = gcnew Random();
        for(int i = 0; i < 3; i++){
            cacheObject[i] = rand->Next(1,4);
            cacheWeight[i] = rand->Next(0, 7);
		}
		
    }
    void Auto1() {
        Reset();
        for (int i = 0; i < 3; i++) {
            cacheObject[i] = i + 1;
            cacheWeight[i] = 3;
        }
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 4; i++) {
            hookY++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        btnBottom->PerformClick();
        hookY--;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 3; i++) {
            hookX++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        hookY++;
        btnBottom->PerformClick();
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        objType = 3;
        hookY--;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        hookX--;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        hookY++;
		btnBottom->PerformClick();
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 2; i++) {
            hookY--;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
		}
        hookX++;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        hookY++;
		btnBottom->PerformClick();
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        hookY--;
		objType = 2;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 2; i++) {
            hookX--;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        for (int i = 0; i < 2; i++) {
            hookY++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        btnBottom->PerformClick();
        for (int i = 0; i < 3; i++) {
            hookY--;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
		}
        for (int i = 0; i < 2; i++) {
            hookX++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        hookY++;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        btnBottom->PerformClick();
		hookY--;
    }
    void Auto2() {
        Reset();
        for (int i = 0; i < 3; i++) {
            cacheObject[i] = i + 1;
            cacheWeight[i] = 3;
        }
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        hookX++;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 4; i++) {
            hookY++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        btnBottom->PerformClick();
        hookY--;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 2; i++) {
            hookX++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        hookY++;
        btnBottom->PerformClick();
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        objType = 1;
        hookY--;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 3; i++) {
            hookX--;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        hookY++;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        
		btnBottom->PerformClick();
        for (int i = 0; i < 2; i++) {
            hookY--;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        for (int i = 0; i < 3; i++) {
            hookX++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        hookY++;
        btnBottom->PerformClick();
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        objType = 3;
        hookY--;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        hookX--;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        for (int i = 0; i < 2; i++) {
            hookY++;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
		btnBottom->PerformClick();
        for (int i = 0; i < 3; i++) {
            hookY--;
            Invalidate();
            Application::DoEvents();
            Sleep(1000);
        }
        hookX++;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        hookY++;
        Invalidate();
        Application::DoEvents();
        Sleep(1000);
        btnBottom->PerformClick();
        hookY--;
    }
  

    MainForm(){
        if (firstTime) {
            CacheSet();
			TowerInit();
			firstTime = false;
        }
    
        this->Text = "symulator dŸwigu";
        this->ClientSize = Drawing::Size(800, 600);
        this->DoubleBuffered = true;

        
        btnLeftTop = gcnew Button();
        btnLeftTop->Text = "Autowie¿a 1";
        btnLeftTop->Location = Point(20, 140);
        btnLeftTop->Size = Drawing::Size(100, 40);

        btnLeftMiddle = gcnew Button();
        btnLeftMiddle->Text = "Autowie¿a 2";
        btnLeftMiddle->Location = Point(20, 190);
        btnLeftMiddle->Size = Drawing::Size(100, 40);

        btnLeftLower = gcnew Button();
        btnLeftLower->Text = "resetuj kontenery";
        btnLeftLower->Location = Point(20, 400);
        btnLeftLower->Size = Drawing::Size(100, 40);

		btnLeftBottom = gcnew Button();
		btnLeftBottom->Text = "resetuj wszystko";
		btnLeftBottom->Location = Point(20, 450);
		btnLeftBottom->Size = Drawing::Size(100, 40);
         

        
        btnBottom = gcnew Button();
        btnBottom->Text = "zamocuj/od³¹cz";
        btnBottom->Size = Drawing::Size(120, 40);
        btnBottom->Location = Point((this->ClientSize.Width - btnBottom->Width) / 2, this->ClientSize.Height - btnBottom->Height - 20);

        
        this->Controls->Add(btnLeftTop);
        this->Controls->Add(btnLeftMiddle);
        this->Controls->Add(btnLeftLower);
		this->Controls->Add(btnLeftBottom);
        this->Controls->Add(btnBottom);

       
        btnLeftTop->Click += gcnew EventHandler(this, &MainForm::OnButtonClick);
        btnLeftMiddle->Click += gcnew EventHandler(this, &MainForm::OnButtonClick);
        btnLeftLower->Click += gcnew EventHandler(this, &MainForm::OnButtonClick);
		btnLeftBottom->Click += gcnew EventHandler(this, &MainForm::OnButtonClick);
        btnBottom->Click += gcnew EventHandler(this, &MainForm::OnButtonClick);

        
        this->KeyPreview = true;
        this->KeyDown += gcnew KeyEventHandler(this, &MainForm::MainForm_KeyDown);

       
        this->Resize += gcnew EventHandler(this, &MainForm::MainForm_Resize);
      
    }

protected:
    virtual void OnPaint(PaintEventArgs^ e) override{
        Form::OnPaint(e);

        Pen^ pen1 = gcnew Pen(Color::FromArgb(255, 252, 186, 3), 3);
        e->Graphics->DrawLine(pen1,180,60,180,540);
        e->Graphics->DrawLine(pen1, 220, 60, 220, 540);
        e->Graphics->DrawLines(pen1, gcnew array<PointF>{
			PointF(180, 540), PointF(220, 500), PointF(180, 460), PointF(220, 420), PointF(180, 380), PointF(220, 340),PointF(180, 300), PointF(220, 260),
            PointF(180, 220), PointF(220, 180), PointF(180, 140), PointF(220, 100), PointF(180, 60), PointF(220, 60), PointF(180, 100),  PointF(220, 140),
			PointF(180, 180), PointF(220, 220), PointF(180, 260), PointF(220, 300), PointF(180, 340), PointF(220, 380),PointF(180, 420), PointF(220, 460),
			PointF(180, 500), PointF(220, 540)
       		});
        Brush^ br1 = gcnew SolidBrush(Color::FromArgb(255, 112, 111, 111));
        e->Graphics->FillRectangle(br1, 70, 65, 60, 100);
        Pen^ pen2 = gcnew Pen(Color::FromArgb(255, 77, 75, 74), 3);
        e->Graphics->DrawRectangle(pen2, 70, 65, 60, 100);
		e->Graphics->DrawLine(pen2, 70, 85, 130, 85);
        e->Graphics->DrawLine(pen2, 70, 105, 130, 105);
        e->Graphics->DrawLine(pen2, 70, 125, 130, 125);
        e->Graphics->DrawLine(pen2, 70, 145, 130, 145);

        for (int i = 0; i < 3; i++) {
            if (cacheObject[i] == 1)
                e->Graphics->FillRectangle(Brushes::Red, 270 + 115 * i, 480, 50, 50);
            else if (cacheObject[i] == 2)
                e->Graphics->FillEllipse(Brushes::Green, 270 + 115 * i, 480, 50, 50);
            else if (cacheObject[i] == 3)
                e->Graphics->FillPolygon(Brushes::Blue, gcnew array<PointF>{
                PointF(270 + 115 * i, 530), PointF(320 + 115 * i, 530), PointF(295 + 115 * i, 480)
            });
        }

        for (int i = 0; i <towerProg; i++) {
            if (towerObjects[i] == 1)
                e->Graphics->FillRectangle(Brushes::Red, 615, 480-50*i, 50, 50);
            else if (towerObjects[i] == 2)
                e->Graphics->FillEllipse(Brushes::Green, 615, 480 - 50 * i, 50, 50);
            else if (towerObjects[i] == 3)
                e->Graphics->FillPolygon(Brushes::Blue, gcnew array<PointF>{
                PointF(615, 530 - 50 * i), PointF(665, 530 - 50 * i), PointF(640, 480 - 50 * i)
            });
        }

		e->Graphics->FillRectangle(br1, 280+115*hookX, 100, 30, 11);
        Pen^ pen3 = gcnew Pen(Color::FromArgb(255, 0, 0, 0), 3);
		e->Graphics->DrawLine(pen3, 295 + 115 * hookX, 110, 295 + 115 * hookX, 280+hookY*50);
        if (objAttached) {
        if(objType==1)
            e->Graphics->FillRectangle(Brushes::Red, 270 + 115 * hookX, 280 + hookY * 50, 50, 50);
        else if(objType==2)
			e->Graphics->FillEllipse(Brushes::Green, 270 + 115 * hookX, 280 + hookY * 50, 50, 50);
        else if(objType==3)
            e->Graphics->FillPolygon(Brushes::Blue, gcnew array<PointF>{
                PointF(270 + 115 * hookX, 330 + hookY * 50), PointF(320 + 115 * hookX, 330 + hookY * 50), PointF(295 + 115 * hookX, 280 + hookY * 50)
		});
        }
		

		e->Graphics->DrawLine(pen1, 80, 80, 720, 80);
        e->Graphics->DrawLine(pen1, 40, 110, 760, 110);
		e->Graphics->DrawLines(pen1, gcnew array<PointF>{ 
			PointF(40, 110), PointF(80, 80), PointF(120, 110), PointF(160, 80), PointF(200, 110), PointF(240, 80), PointF(280, 110), PointF(320, 80),
            PointF(360, 110), PointF(400, 80), PointF(440, 110), PointF(480, 80), PointF(520, 110), PointF(560, 80), PointF(600, 110), PointF(640, 80), 
            PointF(680, 110), PointF(720, 80), PointF(760,110)
        
        });
		Brush^ br2 = gcnew SolidBrush(Color::FromArgb(255, 227, 191, 59));
		e->Graphics->FillRectangle(br2, 185, 70, 70, 90);
		Brush^ br3 = gcnew SolidBrush(Color::FromArgb(255, 15, 55, 79));
        e->Graphics->FillPolygon(br2, gcnew array<PointF>{
            PointF(255, 70), PointF(280, 70), PointF(255,160)
		});
        e->Graphics->FillPolygon(br3, gcnew array<PointF>{
            PointF(255, 75), PointF(275, 75), PointF(260, 130), PointF(255, 130)
        });
        e->Graphics->FillRectangle(br3, 220, 75, 30, 55);

		Brush^ br4 = gcnew SolidBrush(Color::FromArgb(255, 77, 75, 74));
		Brush^ br5 = gcnew SolidBrush(Color::FromArgb(255, 255, 104, 3));
		FontFamily^ ff = gcnew FontFamily("Arial");
        System::Drawing:: Font^ font = gcnew System::Drawing::Font(ff, 10, FontStyle::Bold);
        e->Graphics->FillRectangle(br4, 270, 530, 50, 10);
        e->Graphics->FillRectangle(br4, 385, 530, 50, 10);
        e->Graphics->FillRectangle(br4, 500, 530, 50, 10);
        e->Graphics->FillRectangle(Brushes::Brown, 605, 530, 70, 10);
        e->Graphics->FillRectangle(br1, 0, 540, 800, 60);
        e->Graphics->DrawString("waga: " + cacheWeight[0], font, br5, 270, 527);
        e->Graphics->DrawString("waga: " + cacheWeight[1], font, br5, 385, 527);
        e->Graphics->DrawString("waga: " + cacheWeight[2], font, br5, 500, 527);
		
        
		
        delete pen1;
		delete pen2;
        delete pen3;
        delete br1;
        delete br2;
		delete br3;
        delete br4;
        delete br5;
		delete font;    
		delete ff;
    }

private:
    void OnButtonClick(Object^ sender, EventArgs^ e)
    {
        Button^ btn = safe_cast<Button^>(sender);
        if (btn == btnLeftTop) {
            Auto1();
        }
        else if (btn == btnLeftMiddle){
            Auto2();
        }
        else if (btn == btnLeftLower){
			CacheSet();
		}
        else if(btn == btnLeftBottom){
            Reset();
            
        }
        else if (btn == btnBottom){
            if (objAttached){
               
                if (hookX == 3 && hookY == 4 - towerProg) {
                    if (towerProg<3) {
                        towerProg++;
                        towerObjects[towerProg - 1] = objType;
                        objAttached = false;
                        if (towerProg == 3) {
                            MessageBox::Show("Wie¿a Ukoñczona!", "Gratulacje!", MessageBoxButtons::OK, MessageBoxIcon::Information);
                        }
                    }
                    else {
                        MessageBox::Show("Osi¹gniêto limit wysokoœci wie¿y", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
                else {
                    objAttached = false;
                }
                
            }
            else if (3 > hookX >= 0 && hookY == 4) {
                if (cacheWeight[hookX] < 6) {
                    if (objType == 0) {
                        objType = cacheObject[hookX];
                        objAttached = true;
                        cacheObject[hookX] = 0;
                    }
                    else if (hookX < 3 && objType == cacheObject[hookX]) {
                        objAttached = true;
                        cacheObject[hookX] = 0;
                    }
                    else {
                        MessageBox::Show("Nie mo¿na podnieœæ tego obiektu!", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
                else {
                    MessageBox::Show("Ten obiekt jest zbyt ciê¿ki!", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            
                
               
            
        }
		Invalidate();
    }

    void MainForm_KeyDown(Object^ sender, KeyEventArgs^ e){
        if (e->KeyCode == Keys::W&&hookY>0)
            hookY--;
        else if (e->KeyCode == Keys::A&&hookX>0)
           hookX--;
        else if (e->KeyCode == Keys::S&&hookY<4)
            hookY++;
        else if (e->KeyCode == Keys::D&&hookX<3)
            hookX++;
        Invalidate();
    }

    void MainForm_Resize(Object^ sender, EventArgs^ e){
        btnBottom->Location = Point((this->ClientSize.Width - btnBottom->Width) / 2, this->ClientSize.Height - btnBottom->Height - 20);
    }
};