// jiulou2.c

inherit ROOM;
inherit F_DEALER;

void create()
{
        set("short", "��¥��¥");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳Ժ�
�������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ������
��̹��������ȫ�������Ļ�ɳ����֮���ϵĻ���������Ƹ��ǺƵ�����¥
��ǽ�Ϲ���һ������(paizi)��
LONG
        );
        set("item_desc", ([
                "paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
        ]));
        set("objects", ([
                __DIR__"npc/zhanggui" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));

        set("coor/x",-110);
	set("coor/y",150);
	set("coor/z",10);
	set("coor/x",-110);
	set("coor/y",150);
	set("coor/z",10);
	set("coor/x",-110);
	set("coor/y",150);
	set("coor/z",10);
	set("coor/x",-110);
	set("coor/y",150);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

