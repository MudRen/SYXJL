
// Room: /jingzhou/nvrenjiepu1.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽ֵ���");
        set("long", @LONG
����һ��ר�ž�Ӫ��ҹ�����Ʒ�ľ����꣬���������ٸ�����ν��ã�
���ʮ�ֵ��塣�¼��Ϲ��Ÿ���Ư�����·������Ų�ͬ���ͺš������ϰ���
���ڷ�װ��ƺ���һ�������裬�����Ŵ���Ů���Ӿ���������
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"nvrenjie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}