// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ϻ����ײ������ܹ��߻谵����Ӱ�λΣ��ƺ��м����ڰ��Ķ���
������ߣ�ͨ������˷���  һλ����ؤ�����ֵ��������еĵ��ϡ�����
�����㷢��ǽ���ϻ��ŷ��ֲڵ�·�߲�ͼ��map����
LONG
        );

        set("exits", ([
                "up":__DIR__"inhole",
//              "down":__DIR__"chuchang",
                "1":__DIR__"xcandao1",
                "2":__DIR__"zlandao1",
                "3":__DIR__"slandao1",
                "4":__DIR__"xxandao1",
                "5":__DIR__"wdandao1",
                "6":__DIR__"qzandao1",
                "7":__DIR__"hsandao1",
                "8":__DIR__"shenlongdao1",
                "9":__DIR__"ttaohua1", 
                "10"    : __DIR__"xsandao1",
               "11":__DIR__"dlandao1", 
               "12":__DIR__"yzwandao1",             
 ]));

        set("item_desc",([ "map" : 
                "����һ��ͨ��С�塣\n" +
                "���ڶ���ͨ�����֡�\n" +
                "��������ͨ�����֡�\n" +
                "�����ģ�ͨ�����ޡ�\n" +
                "�����壺ͨ���䵱��\n" +
                "��������ͨ��Ȫ�ݡ�\n" +
                "�����ߣ�ͨ����ɽ��\n"  +
                "���ڰˣ�ͨ����������\n" +
                "���ھţ�ͨ���һ�����\n" +
               "����ʮ��ͨ��ѩɽ�¡�\n" +
               "����ʮһ��ͨ�����Ѵ������\n"  
               "����ʮ����ͨ�������롣\n"        ]));

        set("objects",([
                CLASS_D("gaibang") + "/liang" : 1,
                "/d/city/obj/jitui" : 4,
                "/d/city/obj/jiudai" : 2,
        ]));

        setup();
        replace_program(ROOM);
}

