
// Room: /jingzhou/zhangjuzhengjie.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�ž�����");
        set("long", @LONG
�ٽ�����ľ��ǵ����ؾ���פ�����ˣ�̧ͷ���Կ�����Ӫ��������
�������ڷ������Է��衣�����·��ȴ�ԵñȽϰ��࣬ԭ���ǲ˳���
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "southeast" : __DIR__"caishikou",
                "west"  : __DIR__"jingzhonglu2",
                "north" : __DIR__"bingyingdamen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}