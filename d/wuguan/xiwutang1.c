// Room: /d/wuguan/xiwutang1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "ϰ����");
        set("long", @LONG
����������ڵ�һ��ϰ���ã�����һ����ͷ�ڽ����书����������������
��ͷѧϰ�����������Ϸ����Ÿ��ң�����д�š��Եÿ��п࣬��Ϊ�����ˡ���
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
               "south" : __DIR__"shibanlu2",
        ]));
        setup();
        replace_program(ROOM);
}
