
// Room: /jingzhou/nvrenjiepu5.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽ֵ���");
        set("long", @LONG
һ���ž���һ��ѣĿ����ⱦ����ԭ��������һ��ר�ž�Ӫ�鱦���ε�
�ط����ϰ忴�����Ǹ��������ˣ�����Щ���Ź��ʵĿ�����������Ҫ��һ��
�㣬һ�쵽������Ц�������β�ƺ�����ʵ�����䵹�ܲ������
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"nvrenjie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}