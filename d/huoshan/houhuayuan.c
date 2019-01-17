
// Room: /huoshan/houhuayuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
虽然这里是沙漠的中心，但在天堂峡谷里能长出这些鲜花已经
不再令你感到奇怪了，娇艳的花朵竞相开放，花丛里翩翩起舞的是
一些色彩斑斓的蝴蝶。花丛间隙中的草坪上有一些妖冶的女人，对
你媚眼如丝，你不由得心头一漾。
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "southeast" : __DIR__"xiaojing1",
                "north" : __DIR__"zoulang4",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}