
// Room: /chang'an/xidajie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����Ǻܴ��ʮ�ֽֿڣ����߽��������������ﲻ����������˵�Ǳ�
���ΰ����ĵط������߻��ӣ���˵���֪�������������θ�������֪��
��û�гɹ�������ͨ����¥������ɴ������š�
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"xidajie3",
                "south" : __DIR__"yanhuaxiang",
                "west"  : __DIR__"xidajie1",
                "north" : __DIR__"shajinqiao2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}