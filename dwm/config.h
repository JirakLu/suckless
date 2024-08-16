#pragma once
/* See LICENSE file for copyright and license details. */

/* constants */
#define BROWSER "brave" 
#define STATUSBAR "dwmblocks"
#define TERMINAL "alacritty" 
#define EXPLORER "lfub"

/* appearance */
static const unsigned int refresh_rate      = 144; /* Matches dwm's mouse event processing to your monitor's refresh rate for smoother window interactions. */
static const unsigned int borderpx          = 0;   /* border pixel of windows */
static const unsigned int snap              = 32;  /* snap pixel */
static const unsigned int systraypinning    = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft	    = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing    = 2;   /* systray spacing */
static const int systraypinningfailfirst    = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray                = 1;   /* 0 means no systray */
static const int swallowfloating            = 0;   /* 1 means swallow floating windows by default */
static const int showbar                    = 1;   /* 0 means no bar */
static const int topbar                     = 1;   /* 0 means bottom bar */

static const char *fonts[]          = { "JetBrainsMono NF:size=10", "JoyPixels:size=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrainsMono NF:size=10";
static const char col_gray1[]       = "#2E3440";
static const char col_gray2[]       = "#3B4252";
static const char col_gray3[]       = "#D8DEE9";
static const char col_gray4[]       = "#ECEFF4";
static const char col_cyan[]        = "#434C5E";

static const char *colors[][3]      = {
	/*                 fg          bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/*  class           instance  title           tags mask  isfloating  isterminal   noswallow monitor */
	{ "discord",        NULL,     NULL,           1 << 0,    0,          0,           0,        1 },
	{ "Slack",          NULL,     NULL,           1 << 1,    0,          0,           0,        1 },
	{ "Alacritty",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,             NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact	= 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster	= 1;    /* number of clients in master area */
static const int resizehints	= 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *browsercmd[]  = { BROWSER, NULL };
static const char *explorercmd[]  = { TERMINAL, "-e", EXPLORER, NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
    /* modifier                     key             function        argument */
    { Mod1Mask,                     XK_space,       spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return,      spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,           spawn,          {.v = browsercmd } },
    { MODKEY,                       XK_e,           spawn,          {.v = explorercmd } },
    { MODKEY,                       XK_BackSpace,   spawn,          {.v = (const char*[]){ "sysact", NULL } } },
    { MODKEY,                       XK_p,           spawn,          {.v = (const char*[]){ "passmenu", NULL } } },
    { MODKEY,                       XK_r,           spawn,          {.v = (const char*[]){ "dmenurecord", NULL } } },
    { 0,                            XK_Print,       spawn,          SHCMD ("flameshot gui --clipboard")},
    { MODKEY,                       XK_Print,       spawn,          SHCMD ("flameshot full -p $HOME/Pictures/Screenshots/")},
    { MODKEY|ControlMask,           XK_Print,       spawn,          SHCMD ("flameshot gui -p $HOME/Pictures/Screenshots/")},
    { MODKEY,                       XK_l,           spawn,          SHCMD ("slock")},
    { MODKEY,                       XK_w,           spawn,          SHCMD ("setbg -s ~/Pictures/Wallpapers")},
    { MODKEY|ShiftMask,             XK_q,           quit,           {0} },
    { MODKEY|ControlMask|ShiftMask, XK_q,           quit,           {1} },
    { MODKEY|ShiftMask,             XK_b,           togglebar,      {0} },
    { MODKEY,                       XK_j,           focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,           focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,           incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,           incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,           setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_semicolon,   setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_z,           zoom,           {0} },
    { MODKEY,                       XK_Tab,         view,           {0} },
    { MODKEY,                       XK_q,           killclient,     {0} },
    { MODKEY,                       XK_t,           setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,           setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,           setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,       setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,       togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_f,           togglefullscr,  {0} },
    { MODKEY,                       XK_0,           view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,           tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,       focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period,      focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,       tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period,      tagmon,         {.i = +1 } },
     /* Function keys */
    { 0,    XF86XK_AudioMute,           spawn,  SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
    { 0,    XF86XK_AudioRaiseVolume,    spawn,  SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%+; kill -44 $(pidof dwmblocks)") },
    { 0,    XF86XK_AudioLowerVolume,    spawn,  SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%-; kill -44 $(pidof dwmblocks)") },
    { 0,    XF86XK_AudioNext,           spawn,  SHCMD("playerctl next") },
    { 0,    XF86XK_AudioPrev,           spawn,  SHCMD("playerctl prev") },
    { 0,    XF86XK_AudioPlay,           spawn,  SHCMD("playerctl play-pause") },
    /* Tagkeys */
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
    { ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

