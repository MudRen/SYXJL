// Room: /d/wuguan/changlang5.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�ͨ�������䳡�����Ǽ������߹�����ʱ���˱�̧������
�����������������赹�ġ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "east" : __DIR__"wuguandayuan",
                "west" : __DIR__"xiwuchang",                
        ]));
        setup();
        replace_program(ROOM);
}
