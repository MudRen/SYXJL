//wang.c



inherit NPC;



int execute_ask();

void create()

{

        set_name("������", ({ "wang yuyan", "wang" }));

        set("long", "�����ü�Ϊ��ò,һ˫�۾���������.\n");

        set("nickname", "�����޲�֪");

        set("gender", "Ů��");

        set("age", 20);

        set("attitude","friendly");

        set("str", 30);

        set("dex", 30);

        set("con", 30);

        set("int", 30);

        set("per", 30);

        set("max_qi", 5000);

        set("max_jing", 1000);

        set("neili", 3000);

          set("max_neili", 300);


        set("inquiry", ([
                "����" : "��֪��������������ô���ˣ�����\n",
        "����" : (: execute_ask() :),
  ]));
        setup();

   this_player()->carry_object("/clone/misc/cloth")->wear();
}







void init()

{

        add_action("lingwu","wen");
}





int lingwu(string arg)

{

        object me=this_player(), ob = this_object();

        string special;

        int bl,sl;

        string name;



        if (!sscanf(arg, "%s about %s", name, arg)) return 0;

        if (!id(name)) return 0;



        if (!me->query("luohan_winner")) return notify_fail("�㼶�𲻹��������ڴ�����\n");

        message_vision(

                "$N��$n��̹��ڡ�" + to_chinese(arg) + "�������ʡ�\n", me, ob);

        if (me->is_busy() || me->is_fighting()) {

                command("say ����æ���ء�");

                return 1;

        }

        if (!(special=me->query_skill_mapped(arg))) {

                if (arg == to_chinese(arg))

                        command("say ��" + arg + "����ʲô�书����ô��û��˵����");

                else

                        command("say ��ֻ�ܴ�������⼼���и���ָ�㡣");

                return 1;

        }

        if (!me->query_skill(arg,1)) {

                command("say �㲻�����ּ��ܡ�");

                return 1;

        }

        bl=me->query_skill(arg,1);

if (bl > 180){

  command("say " + RANK_D->query_respect(me) + "������Ź������Ѿ����ܵ㲦����,ֻ�ܿ����Լ�ȥ����ˡ�");

return 1;

}

        if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 50) {

                me->receive_damage("jing",bl/2);

                command("say " + RANK_D->query_respect(me) + "����Ϣһ�°ɡ�");

                return 1;

        }

        sl=me->query_skill(special,1);

        if (bl > sl) {

                command("say " + RANK_D->query_respect(me) + "��"+to_chinese(special)+"���費�����Ҳ���ָ�������һ���"+CHINESE_D->chinese(arg)+"��");

                return 1;

        }

        write("������" + name() + "��ָ�㣬��"+to_chinese(arg)+"�����������һ�㡣\n");

        me->receive_damage("jing",bl/2);

        me->improve_skill(arg,me->query_skill("literate",1)/5+1);

        return 1;

}




int execute_ask ()
{
  object who = this_player();
  object me = this_object();
  object letter = 0;

  if (who->query("combat_exp")<20000)
  {
    command ("say ��˵ʲôѽ��");
    return 1;
  }

  if (environment(me)->query("short")!="ͤ��")
  {
    command ("say ��˵ʲôѽ��");
    return 1;
  }


  command ("nod");
  me->set("given",1);
  letter = new ("/d/mr/obj/letter");
  letter->move(me);
  command ("whisper "+who->query("id")+" ����Ұ�����Ž������ɰɣ�");
  command ("give "+who->query("id")+" "+letter->query("id"));
  if (! who->query("duanwang"))
    who->set("duanwang","got_letter");
  who->set_temp("duanwang","got_letter");
  who->save();
  return 1;
}
