//Room: /d/dali/wfdating.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","������������");
        set("long",@LONG
���˴��������ۿ��Ǵ�����ֻ������һ�飬���ң�д�š������
ʯ���ĸ����֣��������š���î���ʡ��ĸ�С�֣����������������
����һʱҲ����������ࡣ�������������������˰칫֮������
�����ʷ���������һ��ʯ��ͨ����լ��
LONG);
        set("objects",([
            CLASS_D("dali")+"/guanjia": 1,
            __DIR__"npc/jiading": 2,
        ])); 
        set("valid_startroom", 1);        set("exits",([ /* sizeof() == 1 */
            "west"   : __DIR__"zhangfang",
            "east"   : __DIR__"shijing",
            "north"  : __DIR__"zonglichu",
            "out"    : __DIR__"wangfugate",
        ]));
        setup();
        "/clone/board/dali_b"->foo();
}

