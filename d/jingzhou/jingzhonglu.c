
// Room: /jingzhou/jingzhonglu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
�����Ǿ��ݳ�����Ϊ������·�棬������������Ȼ�Ե�ʮ��ӵ������
���ǳ����ĵı�־������̨�������Ǵ˵��ر��Ľ������������߾͵��˱�
�ص�����ˡ�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingzhonglu2",
                "north" :"/d/wuguan/wuguangate",
                "west"  : __DIR__"huatai",
                "south" : __DIR__"jiangjunfu",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
