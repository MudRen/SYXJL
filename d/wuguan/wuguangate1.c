// Room: /d/wuguan/wuguangate.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��ݴ���");
        set("long", @LONG
������һ����լ�ӣ��ſڸ���һ�����ҡ�������ݡ�����������ʯʨ��
��Ӵ��ſ��ƽ�ȥ�����������������������ܷ�æ�����ӣ��ſ�վ������
�������������ϡ�
LONG );
        set("exits", ([
                  "north" : __DIR__"wuguangate",
        ]));
        set("objects", ([
                 __DIR__"npc/xiaoliumang" : 1,
        ]));
        setup();
}

