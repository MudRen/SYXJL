//  �Ϻ�����-by duanfei

#include <ansi.h> 
inherit NPC;
 
void create()
{
        set_name("�Ϻ�����", ({ "nanhai eshen", "eshen" }));
        set("nickname",HIY "�����ɷ"NOR);
        set("long", 
        "��һ���Դ�������Ѱ����һ��������¶����ɭɭ�����ݣ�һ���۾�ȴ����Բ��С��������
�Ŷ��ӣ�Ȼ��С���й�â���䣬�������Ϲ�µµ��һת���㲻�ɵô���һ�����䡣��������
����ģ������׳����֫���������һ�Ը�ˢ��ĺ��ӣ�������ꪣ�ȴ�Ʋ�������Ͷ��
����һ�������ӣ�������ϥ�����������ϵȽ��У����ǻ�������ȴ�������ֲ����ӣ��ۻ�
���ڣ���ɫ�ѱ档ʮ����ָ�ּ��ֳ������缦צ�������ʱֻ��������ò��ª����Խ��Խ��
��������ࡢ�����֫���������Ŵ�磬���Բ��׵����˼�����\n");
        set("gender", "����");
        set("age", 36);
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 20);
      set("con", 35);
        set("dex", 27);
        
        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 120);
        set("combat_exp", 1500000); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.fumo" :),
         })); 
         set_skill("force", 180);
         set_skill("yijin-jing", 180);
         set_skill("dodge", 180);
  

        set_skill("shaolin-shenfa", 180);
        set_skill("cuff", 180);
         set_skill("jingang-quan", 210);
        set_skill("parry", 170);
      
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "jingang-quan");
        prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "/quest/gfjob/npc/npc.h"

