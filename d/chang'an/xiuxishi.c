// Room: /chang'an/xiuxishi.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
��һ�����͸о��������ҵúܣ�����Ҳû�˵������ҵ����ڴ��ϣ���
�������˿�����������Ϣһ�¡�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"xunbufang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}