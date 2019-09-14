from manimlib.imports import *

class Title(Scene):
    def construct(self):
        title = TextMobject(
            "Linear List",
            tex_to_color_map={
                "Linear": YELLOW,
            })
        seqlst = TexMobject(
            "Sequence\ List",
            tex_to_color_map={
                "Sequence": RED,
            })
        lnklst = TexMobject(
            "Linked\ List",
            tex_to_color_map={
                "Linked": BLUE,
            })
        group = VGroup(seqlst, lnklst)
        group.arrange(DOWN)
        VGroup(group, title).arrange(LEFT)
        self.play(Write(title))
        self.wait(0.3)
        self.play(FadeInFrom(group, RIGHT))
        self.wait(0.5)
        defseq = TextMobject(
            "Sequence List: ", "definition"
        )
        defseq[0].set_color(RED)
        defseq[1].set_color(BLUE)
        defseq.move_to(3*UP + 3*LEFT)
        self.play(
            FadeOut(title),
            FadeOut(lnklst),
            Transform(seqlst, defseq)
        )
        self.wait()
        intro1 = TextMobject("Sequence table is a kind of linear table")
        intro2 = TextMobject("stored in compyter memory in the form")
        intro3 = TextMobject("of arrays. As long as the start posttion")
        intro4 = TextMobject("the address of any elements is obtained")
        intro5 = TextMobject("by:   ")
        formula = TexMobject("loc(A_i)=loc(A_0) + L_{element}*i").set_color(YELLOW)
        intrg = VGroup(intro1, intro2, intro3, intro4, intro5).arrange(DOWN)
        VGroup(intrg, formula).arrange(DOWN)
        self.play(Write(intrg))
        self.wait(0.5)
        self.play(Write(formula))
        self.wait(4)

class proc_define(Scene):
    def construct(self):
        title = TextMobject(
            "Sequence List: ", "struct define"
        ).move_to(3*UP + 3*LEFT)
        title[0].set_color(RED)
        title[1].set_color(BLUE)
        self.play(Write(title))
        self.wait() # just for test
        # # TODO: finish the define of sequence by c-like lang
        test = TexMobject(r"\sum n")
        self.play(Write(test))
        self.wait()

# these code is aiming to display the process's action
# use test data: [5, 3, 2, 4, 1]

class proc_build(Scene):
    def construct(self):
        title = TextMobject(
            "Sequence List: ", "build process"
        ).move_to(3*LEFT + 3*UP)
        title[0].set_color(RED)
        title[1].set_color(BLUE)
        self.play(Write(title))
        """
        self.wait()
        # sq1 = Rectangle(height=0.5, width=0.5, color=RED)
        # sq2 = Rectangle(height=0.5, width=0.5, color=RED)
        arr = []
        for i in range(5):
            tmp = Rectangle(height=1, width=1, color=BLUE, fill=RED)
            tmp.move_to(RIGHT*i)
            arr.append(tmp)
        for t in arr:
            self.play(FadeIn(t))
        # sq2.move_to(0.5*LEFT)
        # self.play(FadeIn(sq1), FadeIn(sq2))
        self.wait()
        """
        struct_text = TextMobject("struct ", "SeqList")
        struct_text[0].set_color(BLUE)
        struct_text[1].set_color(GREEN)
        struct_text.move_to(4*LEFT + 2*UP)
        self.play(Write(struct_text))
        elem_arr = TextMobject(
            "ElemType ",
            "list  ",
            "$\\rightarrow$"
        ).move_to(3*LEFT + UP)
        elem_arr[0].set_color(BLUE)
        elem_arr[1].set_color(GREEN)
        elem_arr[2].set_color(RED)
        self.play(
            Write(elem_arr)
        )
        # build array process
        for i in range(5):
            tmp = Rectangle(height=1, width=1, color=YELLOW)
            tmp.move_to(5*RIGHT + 2*UP)
            self.play(tmp.move_to, i*RIGHT + UP)
        len_text = TextMobject("int  ", "len ", "$\\rightarrow$").move_to(2.1*LEFT)
        len_text[0].set_color(BLUE)
        len_text[1].set_color(GREEN)
        len_text[2].set_color(RED)
        self.play(Write(len_text))
        zero_text = TextMobject("$0$").move_to(5*RIGHT)
        zero_text.set_color(PURPLE_A)
        self.play(zero_text.move_to, 0.1*DOWN)
        self.wait()

class proc_destory(Scene):
    def construct(self):
        title = TextMobject(
            "Sequence List: ", "destory process"
        )
        title[0].set_color(RED)
        title[1].set_color(BLUE)
        self.wait()
        # TODO

class proc_getitem(Scene):
    def construct(self):
        title = TextMobject(
            "Sequence List: ", "getitem process"
        )
        title[0].set_color(RED)
        title[1].set_color(BLUE)
        self.wait()
        # TODO

class proc_insert(Scene):
    def construct(self):
        title = TextMobject(
            "Sequence List: ", "insert process"
        )
        title[0].set_color(RED)
        title[1].set_color(BLUE)
        self.wait()
        return None
        # finish just for test
        sqr = Square().to_edge(RIGHT)
        idx = DecimalNumber(number=0)
        idx.add_updater(lambda d: d.next_to(sqr, DOWN))
        self.add(sqr, idx)
        self.play(
            sqr.move_to, LEFT,
        )
        self.wait()


class proc_remove(Scene):
    def construct(self):
        title = TextMobject(
            "Sequence List: ", "remove process"
        )
        title[0].set_color(RED)
        title[1].set_color(BLUE)
        self.wait()
        # TODO
