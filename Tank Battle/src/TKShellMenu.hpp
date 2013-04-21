#pragma once
#include "../include/hgeguictrls.h"
#include "../include/hge.h"
#include "menuitem.h"

class TKShellMenu
    :public hgeGUI
{
public:
    TKShellMenu();
    ~TKShellMenu();
    void Show(bool show);
    void Render();

private:
    HGE                 *_hge;
    hgeSprite*          _bg;
    HEFFECT             _hBgMusic;
    hgeFont*            _font;
    hgeSprite*          _cursor;
};

TKShellMenu::TKShellMenu()
{
    _hge = hgeCreate(HGE_VERSION);
    _bg = new hgeSprite(_hge->Texture_Load("img\\ShellMenuBg.png"),0,0,800,600);

    _hBgMusic = _hge->Effect_Load("music\\pause.ogg");
    _cursor = new hgeSprite(_hge->Texture_Load("img\\cursor.png"), 0, 0, 32, 32);
    _font = new hgeFont("img\\font1.fnt");

    AddCtrl(new hgeGUIMenuItem(1, _font, 0, 185, 300, 0.0f, "Single"));
    AddCtrl(new hgeGUIMenuItem(2, _font, 0, 185, 340, 0.1f, "MultiPlayer"));
    AddCtrl(new hgeGUIMenuItem(3, _font, 0, 185, 380, 0.2f, "About"));
    AddCtrl(new hgeGUIMenuItem(4, _font, 0, 185, 420, 0.3f, "Exit"));

    SetNavMode(HGEGUI_UPDOWN|HGEGUI_CYCLED);
    SetCursor(_cursor);
    SetFocus(1);
    Enter();
}

TKShellMenu::~TKShellMenu()
{
    delete _cursor;
    delete _font;
    delete _bg;
    _hge->System_Shutdown();
    _hge->Release();
}

void TKShellMenu::Show(bool show)
{
    static HCHANNEL h;
    if(show)
    {
        h = _hge->Effect_PlayEx(_hBgMusic, 100, 0, 1.0f, true);
    }
    else
    {
        _hge->Channel_Stop(h);
    }
}

void TKShellMenu::Render()
{
    _hge->Gfx_BeginScene();
    _bg->Render(0,0);
    _font->SetColor(0xFFFFFFFF);
    hgeGUI::Render();
    _hge->Gfx_EndScene();
}