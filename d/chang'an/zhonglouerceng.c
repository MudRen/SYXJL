
// Room: /chang'an/zhonglouerceng.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��¥����");
        set("long", @LONG
����վ����¥��¥����¥�����㣬�����ܣ��Ľ��ܶ���������䣬
���Ի��ȣ�ƾ���������ɱ����ų�ȫò������������һ�ڴ����ӣ�ÿ����
ײ��Ϊ�˱�ʱ�����ʹӽ�����ģ���ԣ���¥��ȫ����¥֮�ڡ�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([                
                "down"  : __DIR__"zhonglou",                             
        ]));

        set("no_clean_up", 0);
        setup();
        "/clone/board/ca_b"->foo();
}
