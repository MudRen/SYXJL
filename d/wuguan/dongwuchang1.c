// Room: /d/wuguan/dongwuchang1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "�����䳡");
        set("long", @LONG
����¶�����䳡���ö�����������������ţ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ��򣬵��Ϸ��ż���������
�ߡ�
LONG );
        set("outdoors", "wuguan");
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"dongwuchang",
                "north" : __DIR__"changlang2",
        ]));
        setup();
        replace_program(ROOM);
}
