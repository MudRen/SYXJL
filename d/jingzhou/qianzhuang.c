
// Room: /jingzhou/qianzhuang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ǯׯ");
        set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ɽ����Ǯׯ���ž�
������������һ����ȫ�����ض��зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��
ȫ����
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"xidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}