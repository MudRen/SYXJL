// Room: /chang'an/yaopu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "ҩ��");
        set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ���
��С������ɢ�������ġ�һ�����ж����ڲ輸�ԣ����Ժ��Ų裬��Ҳ����
��һ�ۡ�һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ���Ѿ����Ƶ�
���(guanggao)��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"yaowangdong",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}