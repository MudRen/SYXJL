
// Room: /jingzhou/duchang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ��������ڽ�
��ƽԭ�����Ϊ�ḻ����Щ����δ�����֣���������ͷ������Ӯ�࣬����
�öĳɷ磬�����������˲��٣����ȴ��ͷɥ������Թ�Լ�����������
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"xidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}