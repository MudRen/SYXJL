
// Room: /jingzhou/nvrenjie1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽�");
        set("long", @LONG
�����������һ����Ů�˽��ˣ��������������ļ������Ǵ��Ư������
���͹����ǣ����˼�����������Ŀ����ӵ�ϲ���������й����⣬��������
��פ�������������һ�ҳ�װ�꣬���ϵ���һ�Ҳ�ƥ�꣬��˵���ҵ��ϰ�
�����油�ϵ�ء�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nanmendajie2",
                "south" : __DIR__"nvrenjiepu4",
                "west"  : __DIR__"nvrenjie2",
                "north" : __DIR__"nvrenjiepu1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}