// xiaolu1.c �ּ�С��
// by Xiang

inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG );
        set("exits", ([
                "west" : __DIR__"guangchang",
                "east" : __DIR__"xiaolu2", 
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

