
// Room: /jingzhou/wanjiacaiyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ҳ�԰");
        set("long", @LONG
��������Ҵ�Ժ��һƬ�����أ�ƽ�����������٣��ݷ���ʱ���£�Ҳ
������������Щũ������ڵĲ�԰���������Ͳˡ��ܲ������ӡ�˿��֮
�ࡣ
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south"  : __DIR__"wanjiahouyuan",
        ]));
        set("objects", ([
                __DIR__"npc/kongxincai" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}