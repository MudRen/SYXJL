// Room: /d/city/lao.c
// Date: Ronger 98/11
// �޸�: tender 99/02/01

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���ݼ���");
        set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ
���Կ�������ƺ��м�����Ӱ��������ת��ͷȥ������������ס
���������ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ���
���ɣ�ֻ���ϱ������һ��С�ţ����Ͽ��˸����ƴ�Ķ�������
�ͷ��õġ��ű���һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��
һ�߰׵÷����Ŀݹǡ�
LONG
        );

        set("objects", ([
                 "/d/city/obj/jitui":3,
                   "/d/city/obj/jiudai":1,
            ]));
        set("valid_startroom",1);
        set("no_dun",1);
        set("no_fight",1);
        setup();

}

void init()
{       
        object ob = this_player();


        if( (int)ob->query_condition("jail") <= 0 )
        {
                message("vision",
                        HIY "ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n\n" NOR, 
                        environment(ob), ob);

                tell_object(ob, "����ٺٵ�Ц�ţ���������������������...��\n");

                ob->set("startroom", "/d/city/lao");
                ob->set("oldtitle",(string)ob->query("title"));
                ob->set("title",HIR "˼����..." NOR);
                ob->apply_condition("jail", 60);
        }

}

