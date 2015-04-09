#
# Plot output from main.c to allow comparison
# of MOBS and Binary Search.
#
# Usage: R --slave --args filename < plot.r
#
# Andrew Turpin
# Thu 27 Feb 2014 17:00:12 EST
#

if (length(commandArgs()) == 4) {
    d <- read.table(commandArgs()[4], stringsAsFactors=FALSE)
} else {
    d <- read.table("/tmp/x", stringsAsFactors=FALSE)
}
l <- split(d, d[,1])

M <- as.numeric(l$M[,6])
B <- as.numeric(l$B[,6])

qRange <- range(d[,7])   # highest number of questions

layout(matrix(1:6,2,3))
par(mgp=c(2,1,0))

ma <- as.numeric(l$M[,6])
ba <- as.numeric(l$B[,6])
mq <- as.numeric(l$M[,7])
bq <- as.numeric(l$B[,7])

hma <- hist(ma, plot=FALSE)
hba <- hist(ba, plot=FALSE)
hmq <- hist(mq, plot=FALSE)
hbq <- hist(bq, plot=FALSE)

hma <- hist(ma, main="MOBS", xlab="Answer",
            ylim=range(hma$counts,hba$counts), xlim=range(ma,ba), col="red")

hba <- hist(ba, main="Bin Search", xlab="Answer", 
            ylim=range(hma$counts,hba$counts), xlim=range(ma,ba), col="blue")

hmq <- hist(mq, main="MOBS", xlab="Number of Questions",
            ylim=range(hmq$counts,hbq$counts), xlim=range(bq,mq), col="red")

hbq <- hist(bq, main="Bin Search", xlab="Number of Questions",
                ylim=range(hmq$counts,hbq$counts), xlim=range(bq,mq), col="blue")

plot(
    c(
        mean(abs(as.numeric(l$M[,6]) - as.numeric(l$M[,4]))), 
        mean(abs(as.numeric(l$B[,6]) - as.numeric(l$B[,4]))) 
    ), 
    c(mean(mq), mean(bq)),
    col=c("red", "blue"),
    xlab="Mean abs(Answer less Target)",
    ylab="Mean No. of presentations",
    pch=19, cex=2
)
cat("\n")
cat(sprintf("                %17s %17s\n","Answer   ","Num Ques.   "))
cat(sprintf("                %7s (%7s) %7s (%7s)\n","mean","sd", "mean","sd"))
cat(sprintf("----------------------------------------------------------\n"))
cat(sprintf("         MOBS   %7.4f (%7.4f) %7.4f (%7.4f)\n", mean(ma), sd(ma), mean(mq), sd(mq)))
cat(sprintf("Binary Search   %7.4f (%7.4f) %7.4f (%7.4f)\n", mean(ba), sd(ba), mean(bq), sd(bq)))
cat("\n")
