library("mongolite")        # Library to interact with mongodb
library("plotrix")          # Library to plot 3D pie chart

# Connect to Mongo server
db <- mongo(db= "employee", collection= "performance")

# Get complete database into a dataframe
all <- db$find()

# Get count of employess, wrt result produced
result_prod <- db$aggregate('[{"$group": {"_id": "$results_prod", "count": {"$sum": 1}}}]')
# Get count of employees, performance wise
perf <- db$aggregate('[{"$group": {"_id":"$performance", "count": {"$sum": 1}}}]')

# Get distinct attributes of results
results <- result_prod$"_id"
# Get distinct attributes of performance
performance <- perf$"_id"

# Create a pie chart to show results produced
piepercent <- round(100*result_prod$count/ sum(result_prod$count), 1)
piepercent <- paste(results, piepercent, "%", sep = " ")    # Append percentage and % to results

png(file = "pie_reslt.png")
pie(x=result_prod$count, labels=piepercent, main="Results Produced", col=c("red","blue"))
dev.off()

# Create 3D pie chart for performance
png(file = "pie3D_perf.jpg")
pie3D(perf$count, labels= performance, explode= 0.1, main= "3D Pie Chart of employee performance")
dev.off()

# Create a histogram to show frequency of employees' attendance
png(file = "hist_attend.jpg")
hist(all$attendance, main= "Attendance Frequency", xlab= "Attendance in Percentage", col= rainbow(length(all$attendance)))
dev.off()

# Barplot with only performance
png(file="bar_perf.png")
barplot(perf$count, names.arg= performance, ylab= "Count", main= "Performance Analysis", xlab= "Performance", col= "blue", border= "red")
dev.off()

# Barplot with Performance and results produced
colors = c("green", "orange")

po <- db$count('{"performance": "poor", "results_prod": "ok"}')
pd <- db$count('{"performance": "poor", "results_prod": "dmg"}')
go <- db$count('{"performance": "good", "results_prod": "ok"}')
gd <- db$count('{"performance": "good", "results_prod": "dmg"}')
ao <- db$count('{"performance": "avg", "results_prod": "ok"}')
ad <- db$count('{"performance": "avg", "results_prod": "dmg"}')

Matrix <- matrix(c(pd,ad,gd,po,ao,go), nrow = 2, ncol = 3, byrow = TRUE)
png(file="bar_perf_res.png")
barplot(Matrix, main= "Performance vs Results Produced", names.arg= performance, xlab= "Performance", ylab= "Employee Count", col= colors)
legend("topleft",results,cex = 1.3, fill=colors)


# Create a scatterplot for Attendance vs Performance
new.perf <- c()
for (p in all$performance)
    if(p == "poor") {
        new.perf <- c(new.perf, runif(1,0.0,1.0))
    } else if(p == "avg") {
    new.perf <- c(new.perf, runif(1,1.0,2.0))
    } else {
    new.perf <- c(new.perf, runif(1,2.0,3.0))
    }

png(file = "scatter.png")
plot(x= all$attendance, y= new.perf, main= "Attendance vs Performance Analysis", xlab= "Attendance", ylab= "Performance")
dev.off()
