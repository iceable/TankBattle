// Tank Battle.cpp : ����Ӧ�ó������ڵ㡣
//
#include "include\hge.h"

#pragma comment(lib, "lib/hge.lib")
#pragma comment(lib, "lib/hgehelp.lib" )

//#pragma comment(linker, "/NODEFAULTLIB:libc.lib")

#include "src\TKGame.h"
#include "src\TKRender.hpp"


HGE* hge;





bool Update()
{
    return false;
}

bool Render()
{
    TKRender& painter = TKRender::GetInstance();
    painter.paint();
    return false;
}

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
    hge = hgeCreate(HGE_VERSION);
    
    hge->System_SetState(HGE_WINDOWED, true ); //�Ƿ񴰿���ʾ
    hge->System_SetState(HGE_LOGFILE, "tank battle.log");
    hge->System_SetState(HGE_SHOWSPLASH, false); 

	hge->System_SetState(HGE_FRAMEFUNC, Update ); //�߼�����
	hge->System_SetState(HGE_RENDERFUNC, Render ); //�滭����

	hge->System_SetState(HGE_FPS, 60 ); //ÿ��60֡
    hge->System_SetState(HGE_SCREENBPP, 32);

	if( hge->System_Initiate() )//�������������õ����ԣ���������
	{
        ItemsLogic& game =  ItemsLogic::GetInstance();
        TKRender& painter = TKRender::GetInstance();
        game.Start();
		hge->System_Start();  //���������ϵ����߼��ͻ滭��ֱ���߼�����true
        hge->Release();
	}
    else
    {
        MessageBox(NULL, hge->System_GetErrorMessage(), "HGE Error:", MB_OK|MB_ICONERROR|MB_APPLMODAL);
    }

    return 0;
}


