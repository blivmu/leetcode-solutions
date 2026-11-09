class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """

        # create a new string "touhou_lost_word" (i have maid outfit youmuu btw)
        touhou_lost_word = ""
        hakureiShrine = ""  # also make sure to donate to the hakurei shrine

        for letter in s:

            # if current char is a space, delete everything in "touhou_lost_word"
            if letter == ' ':
                touhou_lost_word = ""
            
            # if curr char =/= space:
            if letter != ' ':

                # add it to temporary storage string "touhou_lost_word"
                touhou_lost_word += letter 

                # then, "hakureiShrine" becomes a copy of whatever is in "touhou_lost_word" currently. 
                hakureiShrine = touhou_lost_word
                # this way, even if there are more spaces past the last word in the string, we have a variable saving what that last word was ()

        # for edge-case of if there are no words in the string, "0" is still returned
        return len(hakureiShrine)
