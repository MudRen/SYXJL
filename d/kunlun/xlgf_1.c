  // /d/kunllun/xlgf_1.c



#include <ansi.h>

inherit ROOM;



void create()

{

        set("short", "С������");

        set("long", @LONG

�������ŷ���ר�õĴ�������ĵط������˲�ϲ�κ�װ��, ��������ֻ

��һ��СС�����š�ǽ������������ľ�����ź���һ����¯(xianglu)����

���������ػ�����������֮ͼ������������ڸ�����ϰ�������������µ���

���ǽ�����������һ��С��ͨ��ۻ�ͤ��

LONG

        );

        set("exits", ([

                "north" : __DIR__"guanhuat",

                "south" : __DIR__"ceting_w",

        ]));

        



        set("item_desc", ([

                "xianglu" :

"��������ͭ���ɵ���¯����Լ���ٶ�¯�����о���Ϸ���ͼ����

¯�ڻ������������������Ľ�Ҫ��ͷ! Ϊ�˱��ֻ��ƣ����벻ͣ����

¯����(shan)�硣\n",

        ]));



        set("dan_count", 6);

        setup();

}



void init()

{

        add_action("do_shan", "shan");

}



int do_shan(string arg)

{       mapping fam;

        object me;
        int i, costj, costq;



        me = this_player();

        if (me->is_busy())

         {write("��������æ���أ�\n");return 1;}

        if (me->is_fighting())

         {write("������ս���У��޷�ר�ĸɻ\n");return 1;}



        if ( arg != "xianglu" )

            {    message_vision("$N���˰��֣�������������\n",me);

                 return 1;

             }

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")

               return notify_fail("���뱾�����������������ڴ��˷�����!\n");

        costj = 1000 / (int)me->query("con");

        costj = random(costj);

        costq = 1500 / (int)me->query("str");

        costq = random(costq);



        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){

        message_vision("$N�������ͣ�һ������ͷྵ���¯�ϣ�\n",me);

        me->unconcious();return 1;}

        

        me->receive_damage("jing", costj);

        me->receive_damage("qi", costq);       



        message_vision("$N���������������Ż�\n", me);



        if ( (int)me->query_skill("strike", 1) < 31)

                {

                        write(HIY"���ֱ���������������֮���ƺ��Ի����Ʒ���Щ����\n"NOR);

                        me->improve_skill("strike", (int)(me->query("int") / 2));

                }

        if ( (int)me->query_skill("parry", 1) < 31)

                {

                        write(HIY"���ֱ���������������֮���ƺ��Ի����м���Щ����\n"NOR);

                        me->improve_skill("parry", (int)(me->query("int") / 2));

                }

          if ( (int)me->query("combat_exp") < 15000 && me->query("neili") > 100) {

             me->add("combat_exp", (int)(me->query("con") / 6));

             me->add("neili", - random(50));

          }

        i = (int)me->query("int") * (int)me->query("str") / 4;

        i = i + (int)me->query("kar") / 3 - 20+random(8); 

        return 1;}



