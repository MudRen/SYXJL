
// Room: /jingzhou/wanjiahouyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Һ�Ժ");
        set("long", @LONG
���߽���һ��ǳ��򵥵ķ��䣬���լԺ���������ݷ����������ﶺ
��һ���ģ������СŮ����ȴ�Եò�����ôר����ż����Ŀ�������Զ
����������˼��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"wanjiadayuan",
                "north"  : __DIR__"wanjiacaiyuan",                
        ]));
        set("objects", ([
                __DIR__"npc/qifang" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}