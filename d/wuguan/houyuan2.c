// Room: /d/wuguan/houyuan1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ���ˣ����ܶ��ǲ˵أ������Ǹ�Сɽ�£������涼��
�����Χ��Ĳ˵أ����Ÿ����Ĳˣ���ʺ����ã�ҡҡ��׹��������
��ûʲô�˴���
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"houyuan1",
                "east" : __DIR__"caidi",
                "west" : __DIR__"caidi1",                                                
        ]));
        setup();
        replace_program(ROOM);
}
