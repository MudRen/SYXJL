// Room: /u/setup/xiongdong.c



inherit ROOM;



void create()

{

        set("short", "�ܶ�");

        set("long", @LONG

�˴�Ϊһ�ܶ������ڼ��ǿ����а˾�����м�͸��һ����⣬����

�촰һ�㡣�˶���ǰ�м��������ڴ˾Ӵ����������Ŵ�ɽ��ɱ�ܶ�ס�ڴ�

�����ʴ����롢���ʯ�����־ߵ�һӦ��ȫ



LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "out" : __DIR__"shishan",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

