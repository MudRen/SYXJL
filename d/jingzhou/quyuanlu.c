
// Room: /jingzhou/quyuanlu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��ԭ·");
        set("long", @LONG
�����·�����ոշ��¹����������ʯ���������������룬������
ȥ���Ǳ��ص��׸�����ɽ��լԺ�ˣ���˵�����߸�ͽ�ܶ��Ǳ��ص�һЩ��
���ӵܡ���
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"quyuanlu2",
                "west"  : __DIR__"wanjiadazhai",
                "north" : __DIR__"jingzhonglu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}