
// Room: /huoshan/chufang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ��������Ĳ�������������κ�ʱ������������ӡ���
��������˳Է����ܲ�׼ʱ������û��������������Է������˵�
ɫ��ζһӦ��ȫ������Դ̼����ʳ���ˡ�
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "east"  : __DIR__"zoulang1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}